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
int color[1001][3];
int dp[1001][3];
int dp2[1001][3];
int dp3[1001][3];

/* 
rgb
원형
 */

int solution() {
  for (int i=0; i<=1000; i++)
    for (int j=0; j<3; j++) {
      dp[i][j] = INF;
      dp2[i][j] = INF;
      dp3[i][j] = INF;
    }

  // 첫 집 빨강
  dp[1][0] = color[1][0];
  for (int i=2; i<=n; i++)
    for (int j=0; j<3; j++) {
      for (int k=0; k<3; k++)
        if (j != k) dp[i][j] = min(dp[i][j], dp[i-1][k] + color[i][j]);
    }
  // 첫 집 초록
  dp2[1][1] = color[1][1];
  for (int i=2; i<=n; i++)
    for (int j=0; j<3; j++) {
      for (int k=0; k<3; k++)
        if (j != k) dp2[i][j] = min(dp2[i][j], dp2[i-1][k] + color[i][j]);
    }

  // 첫 집 파랑
  dp3[1][2] = color[1][2];
  for (int i=2; i<=n; i++)
    for (int j=0; j<3; j++) {
      for (int k=0; k<3; k++)
        if (j != k) dp3[i][j] = min(dp3[i][j], dp3[i-1][k] + color[i][j]);
    }
  
  return min({dp[n][1], dp[n][2], dp2[n][0], dp2[n][2], dp3[n][0], dp3[n][1]});
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
      cin >> color[i][j];
  }

  cout << solution();
}