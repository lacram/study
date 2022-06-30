import pandas as pd

filename = "dc"
filetype = ".csv"

dfresultDeleted = pd.read_csv(filename+filetype, encoding='UTF-8-sig')

dfresultDeleted["text"] = dfresultDeleted["text"].str.replace("- dc App", "")

dfresultDeleted.to_csv(filename+filetype, encoding='UTF-8-sig')
