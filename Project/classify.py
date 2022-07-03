import pandas as pd

filename = "Project/ex4_deleted"
filetype = ".csv"
moved = filename + "_normal"
deleted = filename + "_deleted"

dfresultMoved = pd.DataFrame()
dfresultDeleted = pd.read_csv(filename+filetype, encoding='UTF-8-sig')

def classify():
  global dfresultDeleted,dfresultMoved
  
  dfresultMoved = dfresultMoved.append(dfresultDeleted[dfresultDeleted['label'].str.contains("normal", na=False, case=False)])
  dfresultDeleted = dfresultDeleted[~dfresultDeleted['label'].str.contains("normal", na=False, case=False)]
  print(dfresultMoved)
  print(dfresultDeleted)

classify()

dfresultMoved.to_csv(moved+filetype, encoding='UTF-8-sig')
dfresultDeleted.to_csv(deleted+filetype, encoding='UTF-8-sig')
