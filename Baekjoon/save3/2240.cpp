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

int t,w;
int arr[1001];
int dp[1001][31];

/* 
dp[i][j] : i초에 j번 움직였을 경우 얻을 수 있는 최대 개수
홀수번 움직이면 2번에 위치
짝수번 움직이면 1번에 위치
 */

int solution() {
  for (int i=1; i<=t; i++)
    for (int j=0; j<=w; j++) {
      dp[i][j] = dp[i-1][j];
      if (j != 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
      // 자두 받음
      if (arr[i] == (j%2)+1) dp[i][j]++;
    }
  
  int ans = 0;
  for (int i=0; i<=w; i++) {
    ans = max(ans, dp[t][i]);
  }

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> t >> w;

  for (int i=1; i<=t; i++){
    cin >> arr[i];
  }

  cout << solution();
}