import pandas as pd

filename = "Project/ex4"
filetype = ".csv"
moved = filename + "_moved"
deleted = filename + "_deleted"

dfresultMoved = pd.DataFrame()
dfresultDeleted = pd.read_csv(filename+filetype, encoding='UTF-8-sig')

def simplify(strs):
  global dfresultDeleted,dfresultMoved
  
  for str in strs:
    dfresultMoved = dfresultMoved.append(dfresultDeleted[dfresultDeleted['text'].str.contains(str, na=False, case=False)])
    dfresultDeleted = dfresultDeleted[~dfresultDeleted['text'].str.contains(str, na=False, case=False)]
    # print(dfresultMoved)
    # print(dfresultDeleted)

strs = ["병신", "새끼", "좆", "시발", "씨발", "한남", "한녀", "지랄", "좃", "ㅄ", "ㅂㅅ", "ㅈㄹ", "미친년", "꼴페미", "애미"]

simplify(strs)

dfresultMoved.to_csv(moved+filetype, encoding='UTF-8-sig')
dfresultDeleted.to_csv(deleted+filetype, encoding='UTF-8-sig')
