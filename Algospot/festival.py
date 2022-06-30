tests = int(input())

for j in range(tests):
  l, d = list(map(int, input().split()))
  li = list(map(int, input().split()))
  mincost = 100000
    
  for i in range(l-d+1):
    day = 1
    total = 0
    for k in range(i, l):
      total += li[k]
      if day >= d:
        if mincost > total / day:
          mincost = total / day

      day += 1
  
  print(format(mincost, ".8f"))