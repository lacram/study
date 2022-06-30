import pandas as pd
import copy

filename = "attackwordch"
filetype = ".csv"

file = pd.read_csv(filename+filetype, encoding='UTF-8-sig')

sentences = set()

print(len(file))

for i in range(len(file)):
  try:
    text = file.iloc[i]['text']
    sentences.add(text)

  except:
    print(str(i) + '번째 행 실패')

print(len(sentences))

tmp = copy.deepcopy(sentences)

for s1 in sentences:
  for s2 in sentences:
    if s1 == s2: continue

    try:
      if s2 in s1:
        tmp.remove(s2)

    except:
      pass

print(len(tmp))

file_updated = pd.DataFrame()

for sentence in tmp:
  try:
    tmp = pd.DataFrame({'text' : [sentence]})
    file_updated = pd.concat([file_updated,tmp])
  except:
    print(str(i) + '번째 행 실패')

file_updated.to_csv(filename+"_updated"+filetype, encoding='UTF-8-sig')
