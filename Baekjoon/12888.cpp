#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
long long dp[62];

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  // i = 높이
  dp[1] = 1;
  dp[2] = 1;
  for (int i=3; i<=n+1; i++){
    long long ret = pow(2,62)-1;
    for (int j=1; j<i; j++){
      ret = min(ret, dp[i-j] + dp[j]*(long long)pow(2,i-j));
    }
    dp[i] = ret;
  }
  
  cout << dp[n+1];
}