#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int h,w;
int board[1000][1000];
int memo[1000][1000][3];
int check[1000][1000];

// 아래 오른쪽 왼쪽
int dx[3] = {1,0,0};
int dy[3] = {0,1,-1};

int solve(int x, int y, int dir){
  if (x == h-1 && y == w-1) return board[x][y];

  int& ret = memo[x][y][dir];
  if (ret != -1) return ret;

  ret = - 100000000;
  check[x][y] = 1;

  for (int i=0; i<3; i++){
    int nx = x+dx[i];
    int ny = y+dy[i];

    if (nx < 0 || nx > h-1 || ny < 0 || ny > w-1 || check[nx][ny])
      continue;
    
    ret =  max(ret, solve(nx,ny,i)+board[x][y]);
  }
  check[x][y] = 0;

  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> h >> w;

  for (int i=0; i<h; i++)
    for (int j=0; j<w; j++)
      cin >> board[i][j];
  
  memset(memo, -1, sizeof(memo));

  cout << solve(0,0,0);
}