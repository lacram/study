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
int arr[1001];
int dp[1001][1001];

/* 
dp[i][j] - i번째 카드까지 추가했을때 카드 j개를 살 수 있는 최소 비용
 */
int solution() {
  for (int i=0; i<=n; i++)
    for (int j=0; j<=n; j++)
      dp[i][j] = INF;
    
  dp[0][0] = 0;
  
  for (int i=1; i<=n; i++) {
    for (int j=0; j<=n; j++) {
      if (j >= i) dp[i][j] = min(dp[i][j-i] + arr[i], dp[i-1][j]);
      else dp[i][j] = dp[i-1][j];
    }
  }

  return dp[n][n];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=1; i<=n; i++){
    cin >> arr[i];
  }

  cout << solution();
}