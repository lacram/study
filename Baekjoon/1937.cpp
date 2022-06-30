#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
int board[500][500];
int dp[500][500];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

int solve(int x, int y){

  int& ret = dp[x][y];
  if (ret != -1) return ret;
  ret = 1;

  for (int i=0; i<4; i++){
    int nx = x+dx[i];
    int ny = y+dy[i];

    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

    if (board[nx][ny] > board[x][y]) 
      ret = max(ret, solve(nx,ny)+1);
  }

  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      cin >> board[i][j];
  
  memset(dp,-1,sizeof(dp));
  
  int ans = 0;

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      ans = max(ans, solve(i,j));
  
  cout << ans;
}