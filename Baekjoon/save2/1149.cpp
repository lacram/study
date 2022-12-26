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
int cost[1000][3];
int dp[1000][3];

/* 
dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0]
dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1]
dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2]
 */

int solution() {
  
  dp[0][0] = cost[0][0];
  dp[0][1] = cost[0][1];
  dp[0][2] = cost[0][2];

  for (int i=1; i<n; i++) {
    dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
    dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
    dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
  }

  return min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
  }

  cout << solution();
}