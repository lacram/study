#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

pair<int,int> board[4][4];
int n;
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,-1,-1,-1,0,1,1,1};
int dead[17];

void swap(int x, int y, int nx, int ny){
  int tmpn = board[x][y].first;
  int tmpd = board[x][y].second;

  board[x][y].first = board[nx][ny].first;
  board[x][y].second = board[nx][ny].second;

  board[nx][ny].first = tmpn;
  board[nx][ny].second = tmpd;
}

int solve(int x, int y){
  pair<int,int> tmp[4][4];
  for (int i=0; i<4; i++)
    for (int j=0; j<4; j++)
      tmp[i][j] = board[i][j];

  // 먹기
  int fishN = board[x][y].first;
  int dir = board[x][y].second;
  dead[fishN] = 1;
  board[x][y].first = -1;

  // 물고기 이동
  for (int i=1; i<=16; i++){
    if (dead[i]) continue;

    int find = false;
    for (int j=0; j<4; j++){
      for (int k=0; k<4; k++){
        if (board[j][k].first == i){
          for (int t=0; t<8; t++){
            int ndir = board[j][k].second+t;
            int nx = j+dx[ndir%8];
            int ny = k+dy[ndir%8];

            if (nx < 0 || ny < 0 || nx >= 4 || ny >=4) continue;
            if (nx == x && ny == y) continue;

            board[j][k].second = ndir;
            swap(j,k,nx,ny);
            find = true;
            break;
          }
        }
        if (find) break;
      }
      if (find) break;
    }
  }
  
  int ret = fishN;

  for (int i=1; i<=3; i++){
    int nx = x+dx[dir%8]*i;
    int ny = y+dy[dir%8]*i;

    if (nx < 0 || ny < 0 || nx >= 4 || ny >=4) continue;
    if (board[nx][ny].first == -1) continue;

    ret = max(ret, solve(nx,ny)+fishN);
  }

  for (int i=0; i<4; i++)
    for (int j=0; j<4; j++)
      board[i][j] = tmp[i][j];

  dead[fishN] = 0;

  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  for (int i=0; i<4; i++){
    for (int j=0; j<4; j++){
      int a,b;
      cin >> a >> b;
      board[i][j] = {a,b-1};
    }
  }

  cout << solve(0,0);
}