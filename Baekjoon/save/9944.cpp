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
char board[30][30];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int ans = INF;

pair<int,pair<int,int>> roll(int x, int y, int dir) {
  int cnt = 0;
  int nx,ny;
  while (1) {
    nx = x+dx[dir]*cnt;
    ny = y+dy[dir]*cnt;

    if (nx < 0 || ny < 0 || nx >= n || ny >= m || board[nx][ny] == '*') break;
    
    board[nx][ny] = '*';
    cnt++;
  }
  return {cnt-1, {nx-dx[dir],ny-dy[dir]}};
}

void unroll(int x, int y, int dir, int cnt) {
  for (int i=0; i<cnt; i++) {
    board[x+dx[dir]*i][y+dy[dir]*i] = '.';
  }
}

bool check() {
  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++) {
      if (board[i][j] == '.') return false;
    }
  return true;
}

void dfs(int depth, int x, int y) {
  if (check()) {
    ans = min(ans, depth);
  }

  for (int dir=0; dir<4; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
  
    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
    if (board[nx][ny] == '*') continue;
    
    pair<int, pair<int,int>> p = roll(nx,ny,dir);
    dfs(depth+1, p.second.first, p.second.second);
    unroll(nx,ny,dir,p.first);
  }
}

int solution() {
  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++)
      if (board[i][j] == '.') {
        board[i][j] = '*';
        dfs(0,i,j);
        board[i][j] = '.';
      }
  
  if (ans == INF) return -1;
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  int cnt = 1;
  while (cin >> n >> m) {
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++)
        cin >> board[i][j];
    }

    cout << "Case " << cnt << ": " << solution() << endl;
    ans = INF;
    cnt++;
  }
}