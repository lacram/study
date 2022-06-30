import pandas as pd

for i in range(100):
  try:
    xlsx = pd.read_excel("comment" + str(i) + ".xlsx")
    xlsx.to_csv("comment" + str(i) + ".csv", encoding="utf-8-sig")
  except:
    print("fail")