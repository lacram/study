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
int dp[17][17][3];
int board[17][17];
int dx[3] = {0,1,1};
int dy[3] = {1,0,1};
vector<vector<int>> dstate = {{0,2},{1,2},{0,1,2}};

/* 
가로 - 0, 0,2 가능
세로 - 1, 1,2 가능
대각선 - 2, 0,1,2 가능
 */

int dfs(int x, int y, int state) {
  if (x == n && y == n) return 1;

  int& ret = dp[x][y][state];
  if (ret != -1) return ret;
  ret = 0;

  for (auto nstate : dstate[state]) {
    int nx = x + dx[nstate];
    int ny = y + dy[nstate];

    if (board[nx][ny]) continue;
    if (nstate == 2) {
      if (board[nx-1][ny] || board[nx][ny-1]) continue;
    }
    if (nx <= 0 || ny <= 0 || nx > n || ny > n) continue;

    ret += dfs(nx,ny,nstate);
  }

  return ret;
}

int solution() {
  memset(dp, -1, sizeof(dp));

  return dfs(1,2,0);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cin >> n;

  for (int i=1; i<=n; i++){
    for (int j=1; j<=n; j++)
      cin >> board[i][j];
  }

  cout << solution();
}