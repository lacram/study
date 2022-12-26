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

/* 
X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
 */

int dp[1000001];

int solution() {
  fill(dp,dp+1000001,INF);
  dp[1] = 0;

  for (int i=2; i<=n; i++) {
    dp[i] = dp[i-1]+1;
    if (i%3 == 0) dp[i] = min(dp[i], dp[i/3] + 1);
    if (i%2 == 0) dp[i] = min(dp[i], dp[i/2] + 1);
  }
  return dp[n];
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