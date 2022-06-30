#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,m;
int board[1001][1001];
int dp[1001][1001];

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  for (int i=1; i<=n; i++){
    string s;
    cin >> s;
    for (int j=1; j<=m; j++)
      board[i][j] = s[j-1]-'0';
  }

  for (int i=0; i<=n; i++)
    for (int j=0; j<=m; j++)
      dp[i][j] = board[i][j];

  int ans = 0;

  for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++){
      if (board[i][j]){
        dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1])+1;
        ans = max(ans, dp[i][j]);
      }
    }

  cout << ans*ans;
}