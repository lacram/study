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
int day[1500002];
int cost[1500002];
int dp[1500002];

/* 
dp[i+day[j]] = max(dp[i+day[j]], dp[i]+cost[j])
 */

int solution() {
  for (int i=1; i<=n+1; i++) {
    dp[i] = max(dp[i], dp[i-1]);
    if (i+day[i] <= n+1) dp[i+day[i]] = max(dp[i+day[i]], dp[i]+cost[i]);
  }

  return dp[n+1];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=1; i<=n; i++){
    cin >> day[i];
    cin >> cost[i];
  }

  cout << solution();
}