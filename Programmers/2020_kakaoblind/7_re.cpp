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

// 우 하 좌 상
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int n;
int visited[100][100][4];

bool check(int nx, int ny, int nx2, int ny2, int dir, vector<vector<int>> board) {
  if (nx < 0 || ny < 0 || nx >= n || ny >= n) return true;
  if (nx2 < 0 || ny2 < 0 || nx2 >= n || ny2 >= n) return true;
  if (board[nx][ny] || board[nx2][ny2]) return true;
  if (visited[nx][ny][dir] || visited[nx2][ny2][(dir+2)%4]) return true;

  return false;
}

// 회전 dir+-1, 두 좌표 바꿔서 +-1
int solution(vector<vector<int>> board) {
  n = board.size();

  priority_queue<vector<int>, vector<vector<int>>, greater<>> q;
  // 거리, x, y, 방향
  q.push({0,0,0,0});
  q.push({0,0,1,2});

  while (!q.empty()) {
    int cost = q.top()[0];
    int x = q.top()[1];
    int y = q.top()[2];
    int dir = q.top()[3];
    int x2 = x + dx[dir];
    int y2 = y + dy[dir];
    q.pop();

    if ((x == n-1 && y == n-1) || (x2 == n-1 && y2 == n-1)) return cost;
  
    for (int i=0; i<4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      int nx2 = x2 + dx[i];
      int ny2 = y2 + dy[i];

      if (check(nx,ny,nx2,ny2,dir,board)) continue;

      visited[nx][ny][dir] = 1;
      visited[nx2][ny2][(dir+2)%4] = 1;
      q.push({cost+1,nx,ny,dir});
      q.push({cost+1,nx2,ny2,(dir+2)%4});
    }
    for (int i=1; i<=3; i+=2) {
      int nx = x;
      int ny = y;
      int ndir = (dir+i)%4;
      int nx2 = x + dx[ndir];
      int ny2 = y + dy[ndir];

      if (check(nx,ny,nx2,ny2,ndir,board)) continue;
      if (dir % 2 == 1) {
        if (board[nx2+dx[dir]][ny2]) continue;
      }
      else {
        if (board[nx2][ny2+dy[dir]]) continue;
      }

      visited[nx][ny][ndir] = 1;
      visited[nx2][ny2][(ndir+2)%4] = 1;
      q.push({cost+1,nx,ny,ndir});
      q.push({cost+1,nx2,ny2,(ndir+2)%4});
    }
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution({{0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0}});

}