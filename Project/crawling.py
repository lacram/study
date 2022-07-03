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

# i*count + i번
for i in range(10):
  url_list = getRandomUrl()
  comment_final = []

  for link in url_list:
    url = "https://www.youtube.com/watch?v=" + link
    print(url)
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

    time.sleep(1)

    # 팝업 닫기
    try:
      driver.find_element_by_css_selector("#dismiss-button > a").click()
    except:
      pass

    # 대댓글 모두 열기
    buttons = driver.find_elements_by_css_selector("#more-replies > a")

    time.sleep(1)

    for button in buttons:
      button.send_keys(Keys.ENTER)
      time.sleep(0.2)
      button.click()

    time.sleep(1)

    # 정보 추출하기
    html_source = driver.page_source
    soup = BeautifulSoup(html_source, 'html.parser')

    comment_list = soup.select("yt-formatted-string#content-text")
    next_url = soup.select("div#dismissible > ytd-thumbnail > #thumbnail")[0]['href']

    for i in range(len(comment_list)):
      temp_comment = comment_list[i].text
      temp_comment = temp_comment.replace('\n', '')
      temp_comment = temp_comment.replace('\t', '')
      temp_comment = temp_comment.replace('    ', '')
      comment_final.append(temp_comment)

  pd_data = {"댓글": comment_final}
  youtube_pd = pd.DataFrame(pd_data)

  youtube_pd.to_excel('C:/Study/Project/test' + str(i*count+i+2) + '.xlsx')
