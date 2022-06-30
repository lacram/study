#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int r,c;
int board[500][500];
int dp[500][500];
int ans[500][500];
int dx[9] = {-1,-1,-1,0,0,0,1,1,1};
int dy[9] = {-1,0,1,-1,0,1,-1,0,1};

int solve(int x, int y){

  int &ret = dp[x][y];
  if (ret != -1) return ret;

  int dir;
  int tmp = 300001;
  for (int k=0; k<9; k++){
    int nx = x+dx[k];
    int ny = y+dy[k];
    
    if (nx < 0 || nx > r-1 || ny < 0 || ny > c-1) continue;
    if (tmp > board[nx][ny]){
      tmp = board[nx][ny];
      dir = k;
    }
  }
  
  if (dir == 4) return ret = x*c+y;
  else return ret = solve(x+dx[dir], y+dy[dir]);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> r >> c;

  for (int i=0; i<r; i++)
    for (int j=0; j<c; j++)
      cin >> board[i][j];

  memset(dp, -1, sizeof(dp));

  for (int i=0; i<r; i++)
    for (int j=0; j<c; j++){
      solve(i,j);
    }
  
  for (int i=0; i<r; i++){
    for (int j=0; j<c; j++){
      int a,b;
      b = dp[i][j] % c;
      a = dp[i][j] / c;
      ans[a][b]++;
    }
  }

  for (int i=0; i<r; i++){
    for (int j=0; j<c; j++)
      cout << ans[i][j] << " ";
    cout << endl;   
  }
}