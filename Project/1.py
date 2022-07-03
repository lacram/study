from konlpy.tag import Okt

okt = Okt()
words = set()
  
f = open('C:\Study\Project\wordfile.txt', 'r')

string = f.read()

li = okt.morphs(string)

li = list(set(li))

print(li)

li.sort()

fi = open('C:\Study\Project\wordfile_sorted.txt', 'w')

for l in li:
  try: 
    fi.write(l+'\n')
  except:
    print(l)

fi.close()