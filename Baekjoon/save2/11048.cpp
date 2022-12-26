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

int n,m;
int board[1001][1001];

/* 
dp[i][j] = max(dp[i-1][j-1], dp[i-1][j], dp[i][j-1])
 */

int solution() {
  for (int i=1; i<=m; i++)
    board[1][i] += board[1][i-1];
  
  for (int i=1; i<=n; i++)
    board[i][1] += board[i-1][1];
  
  for (int i=2; i<=n; i++)
    for (int j=2; j<=m; j++)
      board[i][j] += max({board[i-1][j-1], board[i-1][j], board[i][j-1]});
  
  return board[n][m];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  for (int i=1; i<=n; i++){
    for (int j=1; j<=m; j++)
      cin >> board[i][j];
  }

  cout << solution();
}