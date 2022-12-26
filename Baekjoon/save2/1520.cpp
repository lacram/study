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
int dp[500][500];
int board[500][500];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int dfs(int x, int y) {
  if (x == n-1 && y == m-1) return 1;

  int& ret = dp[x][y];
  if (ret != -1) return ret;
  ret = 0;

  for (int i=0; i<4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
  
    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
    if (board[nx][ny] >= board[x][y]) continue;

    ret += dfs(nx,ny);
  }

  return ret;
}

int solution() {
  memset(dp, 0, sizeof(dp));

  return dfs(0,0);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++)
      cin >> board[i][j];
  }

  cout << solution();
}