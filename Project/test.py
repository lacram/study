import pandas as pd
import re
from konlpy.tag import Okt

filename = "음절"
filetype = ".csv"

file = pd.read_csv(filename+filetype, encoding='UTF-8-sig')
numbers = set()

for i in range(len(file)):
  try:
    text = file.iloc[i]['BIO']
    if text == 'B' or text == 'I':
      b = file.iloc[i]['2']
      number = re.sub(r'[^0-9]', '', b)
      numbers.add(number)

  except:
    print(str(i) + '번째 행 실패')

numbers = sorted(numbers)

f = open('C:\Study\Project/numbers.txt', 'w')

# write 함수를 이용해서 파일에 텍스트 쓰기
for number in numbers:
  try:
    f.write(number+'\n')
  except:
    print(number)
 
# 파일 닫기
f.close()


