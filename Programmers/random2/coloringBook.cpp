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

int visited[100][100];
vector<vector<int>> board;

int m,n;

int dfs(int x, int y, int color) {
  int dx[4] = {0,1,0,-1};
  int dy[4] = {1,0,-1,0};
  visited[x][y] = 1;

  int ret = 1;
  for (int i=0; i<4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
  
    if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
    if (board[nx][ny] != color) continue;
    if (visited[nx][ny]) continue;

    ret += dfs(nx,ny,color);
  }
  return ret;
}

vector<int> solution(int M, int N, vector<vector<int>> picture) {
  m = M;
  n = N;
  
  board = picture;
  memset(visited,0,sizeof(visited));

  int res = 0;
  int cnt = 0;
  for (int i=0; i<m; i++)
    for (int j=0; j<n; j++) {
      if (!visited[i][j] && board[i][j]) {
        res = max(res, dfs(i,j,board[i][j]));
        cnt++;
      }
    }

  return {cnt, res};
}