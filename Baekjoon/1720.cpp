#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

int dp[31];

int solve(int n){
  if (n<=1) return 1;

  int &ret = dp[n];
  if (ret!=-1) return ret;

  ret = 0;
  ret += solve(n-1) + solve(n-2)*2;

  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;

  cin >> n;
  memset(dp, -1 ,sizeof(dp));
  dp[0] = dp[1] = 1;
  
  int total = solve(n);
  int asym = n%2 == 0 ? dp[n/2]+dp[n/2-1]*2 : dp[n/2];

  cout << (total+asym) / 2 ;
  
  
}