#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#define endl '\n'
#define INF 2000000000

using namespace std;

int n;
// 기존 보드보다 2칸씩 더 있다고 가정
int board[503][503];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

/* 
방향 좌 하 우 상
     1  1  2  2
     3  3  4  4
 */

int getAlpha(int sand) {
  sand = sand - sand / 20 - sand / 10 - sand / 10 - sand * 7 / 100 - sand * 7 / 100 - sand / 50 - sand / 50 - sand / 100 - sand / 100;
  return sand;
}

void tornadoLeft(int x, int y) {
  int sand = board[x][y];
  board[x][y-2] += sand / 20;
  board[x-1][y-1] += sand / 10;
  board[x+1][y-1] += sand / 10;
  board[x+1][y] += sand * 7 / 100;
  board[x-1][y] += sand * 7 / 100;
  board[x-2][y] += sand / 50;
  board[x+2][y] += sand / 50;
  board[x-1][y+1] += sand / 100;
  board[x+1][y+1] += sand / 100;
  board[x][y-1] += getAlpha(sand);
}

void tornadoDown(int x, int y) {
  int sand = board[x][y];
  board[x+2][y] += sand / 20;
  board[x+1][y-1] += sand / 10;
  board[x+1][y+1] += sand / 10;
  board[x][y+1] += sand * 7 / 100;
  board[x][y-1] += sand * 7 / 100;
  board[x][y+2] += sand / 50;
  board[x][y-2] += sand / 50;
  board[x-1][y-1] += sand / 100;
  board[x-1][y+1] += sand / 100;
  board[x+1][y] += getAlpha(sand);
}

void tornadoRight(int x, int y) {
  int sand = board[x][y];
  board[x][y+2] += sand / 20;
  board[x+1][y+1] += sand / 10;
  board[x-1][y+1] += sand / 10;
  board[x-1][y] += sand * 7 / 100;
  board[x+1][y] += sand * 7 / 100;
  board[x-2][y] += sand / 50;
  board[x+2][y] += sand / 50;
  board[x-1][y-1] += sand / 100;
  board[x+1][y-1] += sand / 100;
  board[x][y+1] += getAlpha(sand);
}

void tornadoUp(int x, int y) {
  int sand = board[x][y];
  board[x-2][y] += sand / 20;
  board[x-1][y-1] += sand / 10;
  board[x-1][y+1] += sand / 10;
  board[x][y+1] += sand * 7 / 100;
  board[x][y-1] += sand * 7 / 100;
  board[x][y+2] += sand / 50;
  board[x][y-2] += sand / 50;
  board[x+1][y-1] += sand / 100;
  board[x+1][y+1] += sand / 100;
  board[x-1][y] += getAlpha(sand);
}

void tornado(int x, int y, int dir) {
  if (dir == 0) tornadoLeft(x,y);
  else if (dir == 1) tornadoDown(x,y); 
  else if (dir == 2) tornadoRight(x,y);
  else tornadoUp(x,y);
  board[x][y] = 0;
}

int getAns() {
  int ans = 0;

  for (int i=0; i<2; i++)
    for (int j=0; j<n+4; j++)
      ans += board[i][j];
  
  for (int i=n+2; i<n+4; i++)
    for (int j=0; j<n+4; j++)
      ans += board[i][j];

  // 2~n-1
  for (int i=0; i<2; i++)
    for (int j=2; j<n+2; j++)
      ans += board[j][i];
  
  for (int i=n+2; i<n+4; i++)
    for (int j=2; j<n+2; j++)
      ans += board[j][i];
  
  return ans;
}

void print() {
  for (int i=0; i<n+4; i++) {
    for (int j=0; j<n+4; j++)
      cout << board[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}

int move() {
  int x = n/2+2;
  int y = n/2+2;
  int len = 1;
  int cnt = 0;

  while (1){

    for (int i=0; i<4; i++) {
      for (int j=0; j<len; j++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // bool flag = false;
        // if (board[nx][ny]) {
        //   flag = true;
        //   print();
        // }
        tornado(nx,ny,i);
        // if (flag) print();

        x = nx;
        y = ny;

        if (x == 2 && y == 2) return getAns();
      }
      cnt++;
      if (cnt == 2) {
        cnt = 0;
        len++;
      }
    }
  }
  
}

int solution() {
  return move();
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=2; i<n+2; i++){
    for (int j=2; j<n+2; j++)
      cin >> board[i][j];
  }

  cout << solution();
}