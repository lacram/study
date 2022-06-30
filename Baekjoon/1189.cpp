#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int h,w,k;
string board[5];
int visited[5][5];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int solve(int len, int x, int y){
  if (x == 0 && y == w-1){
    if (len == k) return 1;
    else return 0;
  }

  int ret = 0;  
  visited[x][y] = 1;

  for (int i=0; i<4; i++){
    int nx = x+dx[i];
    int ny = y+dy[i];

    if (nx < 0 || ny < 0 || nx >= h || ny >= w || board[nx][ny] == 'T') continue;
    if (visited[nx][ny]) continue;

    ret += solve(len+1,nx,ny);
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

  cin >> h >> w >> k;

  for (int i=0; i<h; i++)
    cin >> board[i];

  cout << solve(1,h-1,0);

}