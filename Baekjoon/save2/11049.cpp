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
int arr[501][2];
int dp[501][501];

int solution() {
  for (int i=0; i<=n; i++)
    for (int j=0; j<=n; j++)
      dp[i][j] = INF;
  
  // 간격
  for (int t=0; t<n; t++) {
    for (int i=1; i+t<=n; i++) {
      int j = i+t;
      dp[i][i] = 0;
      for (int k=i; k<j; k++) {
        dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+arr[i][0]*arr[k][1]*arr[j][1]);
      }
    }
  }
  return dp[1][n];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=1; i<=n; i++){
    cin >> arr[i][0] >> arr[i][1];
  }

  cout << solution();
}