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
if (cost[k] < cost[j]) dp[i][j] = dp[i][k] + dp[k][j] - 1;

 */

vector<int> dp(1001, 1);
int cost[1001];

int solution() {
  dp[n] = 1;
  for (int i=n-1; i>=1; i--) {
    for (int j=i; j<=n; j++) {
      if (cost[i] < cost[j]) {
        dp[i] = max(dp[i], dp[j]+1);
      }
    }
  }
  return *max_element(dp.begin(), dp.end());
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=1; i<=n; i++){
    cin >> cost[i];
  }

  cout << solution();
}