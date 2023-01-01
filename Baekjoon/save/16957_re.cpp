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
int ans[500][500];
int dx[9] = {-1,-1,-1,0,0,0,1,1,1};
int dy[9] = {-1,0,1,-1,0,1,-1,0,1};

pair<int,int> dp[500][500];

pair<int,int> solve(int x, int y){

  pair<int,int>& pos = dp[x][y];
  if (pos.first != -1) return pos;

  int ret = 300000;
  int dir = -1;
  for (int i=0; i<9; i++){
    int nx = x+dx[i];
    int ny = y+dy[i];

    if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;

    if (ret > board[nx][ny]){
      ret = board[nx][ny];
      dir = i;
    }
  }

  if (dir == 4) {
    pos.first = x;
    pos.second = y;
    return pos;
  }
  else {
    return pos = solve(x+dx[dir],y+dy[dir]);
  }
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
  
  for (int i=0; i<r; i++)
    for (int j=0; j<c; j++)
      dp[i][j] = make_pair(-1,-1);
  
  for (int i=0; i<r; i++)
    for (int j=0; j<c; j++)
      ans[solve(i,j).first][solve(i,j).second]++;
  
  for (int i=0; i<r; i++){
    for (int j=0; j<c; j++)
      cout << ans[i][j] << " ";
    cout << endl;
  }
} 