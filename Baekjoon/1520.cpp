#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,m,ans;
int board[500][500];
bool visited[500][500];
int memo[500][500][4];
// 오른쪽, 아래, 왼쪽, 위
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

// dir방향으로 (x,y)에 갔을때 나오는 경로의 수
int dfs(int x, int y, int dir){
  if (x == n-1 && y == m-1){
    return 1;
  }
  int& ret = memo[x][y][dir];
  if (ret != -1) return ret;
  ret = 0;

  for (int i=0; i<4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
    if (board[nx][ny] >= board[x][y]) continue;

    ret += dfs(nx,ny,i);
  }
  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++)
      cin >> board[i][j];
  
  memset(memo, -1, sizeof(memo));

  cout << dfs(0,0,0);
}