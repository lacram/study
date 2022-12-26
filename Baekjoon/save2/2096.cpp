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
int arr[100001][3];
// i, 위치, max/min
int dp[2][3];

/* 
dp[i][0] = max(dp[i-1][0], dp[i-1][1]) + arr[i][0]
dp[i][1] = max(dp[i-1][0], dp[i-1][1], dp[i-1][2]) + arr[i][1]
dp[i][2] = max(dp[i-1][2], dp[i-1][1]) + arr[i][2]
 */

pair<int,int> solution() {
  for (int i=1; i<=n; i++) {
    dp[i%2][0] = max(dp[(i-1)%2][0], dp[(i-1)%2][1]) + arr[i][0];
    dp[i%2][1] = max({dp[(i-1)%2][0], dp[(i-1)%2][1], dp[(i-1)%2][2]}) + arr[i][1];
    dp[i%2][2] = max(dp[(i-1)%2][2], dp[(i-1)%2][1]) + arr[i][2];
  }
  int maxScore = max({dp[n%2][0],dp[n%2][1],dp[n%2][2]});
  memset(dp,0,sizeof(dp));

  for (int i=1; i<=n; i++) {
    dp[i%2][0] = min(dp[(i-1)%2][0], dp[(i-1)%2][1]) + arr[i][0];
    dp[i%2][1] = min({dp[(i-1)%2][0], dp[(i-1)%2][1], dp[(i-1)%2][2]}) + arr[i][1];
    dp[i%2][2] = min(dp[(i-1)%2][2], dp[(i-1)%2][1]) + arr[i][2];
  }

  return {maxScore, min({dp[n%2][0],dp[n%2][1],dp[n%2][2]})};
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=1; i<=n; i++){
    for (int j=0; j<3; j++) 
      cin >> arr[i][j];
  }

  pair<int,int> ans = solution();
  cout << ans.first << " " << ans.second;
}