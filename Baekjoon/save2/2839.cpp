#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#define endl '\n'
#define INF 2000000000

using namespace std;

int n;
int dp[5001];
/* 
dp
dp[n] = min(dp[n-3] + 1, dp[n-5] + 1)
 */

int solution() {
  fill(dp,dp+5001,INF);
  dp[0] = 0;
  dp[3] = 1;
  dp[5] = 1;

  for (int i=5; i<=n; i++) {
    dp[i] = min(dp[i-3]+1, dp[i-5]+1);
  }
  return dp[n] >= INF ? -1 : dp[n];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  cout << solution();
}