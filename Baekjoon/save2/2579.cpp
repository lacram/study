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
// 계단수, 연속해서 계단을 밟은 수
vector<vector<int>> dp(301, vector<int>(3,0));
int cost[301];

/* 
계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
마지막 도착 계단은 반드시 밟아야 한다.

dp[i] = max(dp[i-2][0~2], dp[i-1][0~1]) + cost[i]
 */

int solution() {
  dp[1][1] = cost[1];

  dp[2][1] = cost[2];
  dp[2][2] = cost[1] + cost[2];

  for (int i=3; i<=n; i++) {
    dp[i][1] = *max_element(dp[i-2].begin(), dp[i-2].end()) + cost[i];
    dp[i][2] = dp[i-1][1] + cost[i];
  }

  return *max_element(dp[n].begin(), dp[n].end());
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