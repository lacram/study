#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;
int *dp;

int solve(int n){
  if (n==1) return 0;

  int &ret = dp[n];
  if (ret!=-1) return ret;

  ret = 9999;
  if (n%3==0) ret = min(ret, solve(n/3)+1);
  if (n%2==0) ret = min(ret, solve(n/2)+1);
  ret = min(ret, solve(n-1)+1);

  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  // ifstream cin;
  // cin.open("input.txt");

  int n;
  cin >> n;

  dp = new int[n+1];
  for (int i=0; i<=n; i++)
    dp[i] = -1;

  cout << solve(n);
  
}