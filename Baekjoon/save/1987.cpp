#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

int w, h;
char board[22][22];
int used[26] = {0};
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
//A 65
int solve(int x, int y){
  used[board[x][y]-65] = 1;

  int ret = 1;
  
  for (int i=0; i<4; i++){
    int nx = x+dx[i];
    int ny = y+dy[i];

    if (!used[board[nx][ny]-65] && board[nx][ny] != '0'){
      ret = max(ret, solve(nx, ny)+1);
      used[board[nx][ny]-65] = 0;
    }
  }
  
  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> h >> w;

  for (int i=0; i<22; i++)
    for (int j=0; j<22; j++)
      board[i][j] = '0';

  for (int i=0; i<h; i++)
    for (int j=0; j<w; j++)
      cin >> board[i][j];

  cout << solve(0,0);
}