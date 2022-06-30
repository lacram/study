from os import pipe
from selenium import webdriver
import time
from openpyxl import Workbook
import pandas as pd
from selenium.webdriver.common.keys import Keys
from webdriver_manager.chrome import ChromeDriverManager
from bs4 import BeautifulSoup
import random
import json
import urllib.request
import string
from openpyxl.cell.cell import ILLEGAL_CHARACTERS_RE

count = 10

def getRandomUrl():
  global count
  API_KEY = 'AIzaSyAsVmFPfl8r6CWSOwyorfM6Efm-XJe_pYo'
  rand = ''.join(random.choice(string.ascii_uppercase + string.digits) for _ in range(3))
  
  urlData = "https://www.googleapis.com/youtube/v3/search?key={}&maxResults={}&part=snippet&type=video&relevanceLanguage=ko&regionCode=KR".format(
      API_KEY, count, rand)

  webURL = urllib.request.urlopen(urlData)
  data = webURL.read()
  encoding = webURL.info().get_content_charset('utf-8')
  results = json.loads(data.decode(encoding))

  url_list = []

  for data in results['items']:
    videoId = (data['id']['videoId'])
    url_list.append(videoId)

  return url_list

wb = Workbook(write_only=True)
ws = wb.create_sheet()

# 셀레니움 옵션 설정
options = webdriver.ChromeOptions()
# 크롬 띄우는 창 없애기
options.add_argument('headless')
# 크롬드라이버 창크기
options.add_argument('window-size=1920x1080')
# 그래픽 성능 낮춰서 크롤링 성능 쪼금 높이기
options.add_argument("disable-gpu")
# 네트워크 설정
options.add_argument(
    "user-agent=Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/61.0.3163.100 Safari/537.36")
# 사이트 주언어
options.add_argument("lang=ko_KR")

driver = webdriver.Chrome(ChromeDriverManager().install(), chrome_options=options)

# 크롤링 시작

next_url = "/watch?v=P4q8I8D_xjs"

for num in range(5):
  comment_final = []
  for i in range(10):

    url = "https://www.youtube.com" + next_url
    print("URL : " + url)
    driver.get(url)
    driver.implicitly_wait(3)

    time.sleep(1)

    driver.execute_script("window.scrollTo(0, 800)")
    time.sleep(2)

    # 페이지 끝까지 스크롤
    last_height = driver.execute_script(
        "return document.documentElement.scrollHeight")
    while True:
        driver.execute_script(
            "window.scrollTo(0, document.documentElement.scrollHeight);")
        time.sleep(1)

        new_height = driver.execute_script(
            "return document.documentElement.scrollHeight")
        if new_height == last_height:
            break
        last_height = new_height

    print("--------------스크롤 완료--------------")
    time.sleep(1)

    # 팝업 닫기
    try:
      driver.find_element_by_css_selector("#dismiss-button > a").click()
    except:
      pass

    time.sleep(1)

    # 대댓글 모두 열기
    buttons = driver.find_elements_by_css_selector("#more-replies > a")

    time.sleep(5)

    for button in buttons:
      button.send_keys(Keys.ENTER)
      time.sleep(0.1)
      try :
        button.click()
      except:
        print("Click Fail")

    print("--------------대댓글 열기 완료--------------")
    time.sleep(1)

    # 정보 추출하기
    html_source = driver.page_source
    soup = BeautifulSoup(html_source, 'html.parser')

    comment_list = soup.select("yt-formatted-string#content-text")
    rand = random.randint(0,5)
    next_url = soup.select("div#dismissible > ytd-thumbnail > #thumbnail")[rand]['href']

    for j in range(len(comment_list)):
      temp_comment = comment_list[j].text
      temp_comment = temp_comment.replace('\n', '')
      temp_comment = temp_comment.replace('\t', '')
      temp_comment = temp_comment.replace('    ', '')
      # openpyxl.utils.exceptions.IllegalCharacterError
      temp_comment = ILLEGAL_CHARACTERS_RE.sub(r'',temp_comment)
      comment_final.append(temp_comment)
    
    print(num*(i+1) + i+1, end="")
    print("번째 페이지 크롤링 완료")

  pd_data = {"댓글": comment_final}
  youtube_pd = pd.DataFrame(pd_data)

  youtube_pd.to_excel('C:/Study/Project/comment' + str(num + 80) + '.xlsx')
