import os

file_path = 'D:\\강의 녹화\\프로그래밍 언어론'
file_names = os.listdir(file_path)

for name in file_names:
  src = os.path.join(file_path, name)
  if name[0].isalpha():
    dst = name[4:]
    dst = os.path.join(file_path, dst)
    os.rename(src, dst)
