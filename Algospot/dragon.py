import sys
limit_number = 1000000
sys.setrecursionlimit(limit_number)

n = 42
srt = 764853475

dp = [2]

for i in range(1,n+1):
  dp.append(dp[i-1]*2+1)

str = "FX+YF"

def solve(srt, n):
  if srt < 5:
    return str[srt]

  if srt == dp[n]//4 or srt == dp[n]//2:
    return '+'
  if srt == dp[n]-1-dp[n]//4:
    return '-'
  
  if srt < dp[n]//2:
    return solve(srt, n-1)

  if dp[n]//2 < srt <=dp[n]:
    return solve(srt-dp[n]//2-1, n-1)

for i in range(srt-1, srt+29):
  print(solve(i, n), end=" ")
