#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,m;
int board[1000][1000];
int visited[1000][1000];
int dp[1000][1000][4][2];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int solve(int x, int y, int dir, bool canBreak){
  if (x == n-1 && y == m-1) 
    return 1;

  int& ret = dp[x][y][dir][canBreak];
  if (ret != -1) return ret;
  ret = 1000000;

  visited[x][y] = 1;

  for (int i=0; i<4; i++){
    int nx = x+dx[i];
    int ny = y+dy[i];

    if (nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny]) continue; 

    if (board[nx][ny]) {
      if (canBreak) ret = min(ret, solve(nx,ny,i,0)+1);
    }
    else ret = min(ret, solve(nx,ny,i,canBreak)+1);
  }
  visited[x][y] = 0;

  return ret;
}


int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  for (int i=0; i<n; i++){
    string a;
    cin >> a;
    for (int j=0; j<m; j++)
      board[i][j] = a[j]-'0';
  }

  memset(dp,-1,sizeof(dp));
  
  int ans = solve(0,0,0,1);

  if (ans == 1000000) cout << -1;
  else cout << ans;
}