import pandas as pd
from konlpy.tag import Okt

filename = "swearword11"
filetype = ".csv"

file = pd.read_csv(filename+filetype, encoding='UTF-8-sig')
okt = Okt()
words = set()

for i in range(len(file)):
  try:
    text = file.iloc[i]['label']
    li = okt.morphs(text)
    words.update(li)
    print(li)
  except:
    print(str(i) + '번째 행 실패')
  
f = open('C:\Study\Project\wordfile.txt', 'w')

# write 함수를 이용해서 파일에 텍스트 쓰기
for word in words:
  try:
    f.write(word+'\n')
  except:
    print(word)
 
# 파일 닫기
f.close()


