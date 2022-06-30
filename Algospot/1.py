test = int(input())

def gen(price, taken, tf):
  global cnt
  if len(price) == n:
    if int(price) < int(e) and int(price) % m == 0:
      cnt+=1
      cnt%=10000007
    return

  t = tf
  for i in range(n):
    if not taken[i] and (i==0 or digits[i-1] != digits[i] or taken[i-1]):
      if digits[i] < e[i]:
        t = True
      if t or digits[i] == e[i]:
        taken[i] = True
        gen(price + digits[i], taken, t)
        taken[i] = False
      
for i in range(test):
  e, m = list(input().split())
  digits = "".join(sorted(e))
  m = int(m)
  n = len(e)

  cnt=0
  taken = [0]*n

  gen("", taken, False)
  print(cnt)
