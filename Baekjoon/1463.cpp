#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

int dp[1000001];

int solve(int n){
  if (n==1) return 0;

  int 
  ret = 99999;

  if (n%3==0) ret = min(ret, solve(n/3)+1);
  if (n%2==0) ret = min(ret, solve(n/2)+1);
  ret = min(ret, solve(n-1)+1);

  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  

  int n;

  cin >> n;
  memset(dp, -1, sizeof(dp));
  
  cout << solve(n);
  
  
}