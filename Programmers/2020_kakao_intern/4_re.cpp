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

/* bfs
1. 직진 100, 코너 500
2. 현재 방향이 홀수 일시 짝수는 코너, 짝수 일시 홀수는 코너
 */

// 우하좌상
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int bfs(vector<vector<int>> board) {
  priority_queue<pair<pair<int,int>,pair<int,int>>, vector<pair<pair<int,int>,pair<int,int>>>, greater<pair<pair<int,int>,pair<int,int>>>> pq;
  // 비용, {x,y}
  int n = board.size();
  int costBoard[25][25][4];
  
  for (int i=0; i<25; i++)
    for (int j=0; j<25; j++)
      for (int k=0; k<4; k++)
        costBoard[i][j][k] = INF;

  pq.push({{0,0},{0,0}});
  pq.push({{0,1},{0,0}});

  while (!pq.empty()) {
    int cost = pq.top().first.first;
    int dir = pq.top().first.second;
    int x = pq.top().second.first;
    int y = pq.top().second.second;

    pq.pop();

    if (x == n-1 && y == n-1) return cost;
    
    // 직진
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if (!(nx < 0 || ny < 0 || nx >= n || ny >= n) &&
       !(board[nx][ny]) &&
       !(costBoard[nx][ny][dir] <= 100+cost) ) {
         costBoard[nx][ny][dir] = 100+cost;
          pq.push({{100+cost,dir},{nx,ny}});
    }
    

    // 코너링
    // 오른쪽 또는 왼쪽 방향
    if (dir % 2 == 0) {
      for (auto ndir : {1,3}) {
        nx = x + dx[ndir];
        ny = y + dy[ndir];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (board[nx][ny]) continue;
        if (costBoard[nx][ny][ndir] <= 600+cost) continue;

        costBoard[nx][ny][ndir] = 600+cost;
        pq.push({{600+cost,ndir},{nx,ny}});
      }
    }
    else {
      for (auto ndir : {0,2}) {
        nx = x + dx[ndir];
        ny = y + dy[ndir];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (board[nx][ny]) continue;
        if (costBoard[nx][ny][ndir] <= 600+cost) continue;

        costBoard[nx][ny][ndir]= 600+cost;
        pq.push({{600+cost,ndir},{nx,ny}});
      }
    }
  }
}

int solution(vector<vector<int>> board) {
  int n = board.size();
  return bfs(board);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution({{0,0,1,0},{0,0,0,0},{0,1,0,1},{1,0,0,0}});

}