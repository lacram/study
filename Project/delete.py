import os

for i in range(100):
  try:
    os.remove("comment" + str(i) + ".csv")
  except:
    pass