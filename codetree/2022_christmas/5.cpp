#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#define endl '\n'
#define INF 2000000000

using namespace std;

int n,m;
int ans = INF;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int board[1000][1000];
int dist[1000][1000][2];
int visitedTP[100000][2];
vector<vector<pair<int,int>>> teleport(100000);


/* 
-2는 선물을, -1은 벽을, 0은 빈 칸을, 그리고 10 이상의 수들은 텔레포트가 가능한 공간
0-1 bfs
 */

void bfs() {
  deque<vector<int>> dq;
  // key, x,y
  dq.push_back({0,0,0});
  dist[0][0][0] = 0;

  while (!dq.empty()) {
    int key = dq.front()[0];
    int x = dq.front()[1];
    int y = dq.front()[2];
    dq.pop_front();

    // 이동
    for (int i=0; i<4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      int nk = board[nx][ny] == -2 ? 1 : key;
    
      if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if (board[nx][ny] == -1) continue;
      if (dist[nx][ny][nk] <= dist[x][y][key]) continue;

      dist[nx][ny][nk] = dist[x][y][key];

      dq.push_front({nk,nx,ny});
    } 

    // 텔레포트
    if (board[x][y] < 10) continue;
    if (visitedTP[board[x][y]][key]) continue;
    visitedTP[board[x][y]][key] = 1;

    for (auto next : teleport[board[x][y]]) {
      int nx = next.first;
      int ny = next.second;

      if (dist[nx][ny][key] <= dist[x][y][key]+1) continue;

      dist[nx][ny][key] = dist[x][y][key]+1;
      dq.push_back({key,nx,ny});
    }
  }

}

int solution() {
  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++)
      for (int k=0; k<2; k++)
        dist[i][j][k] = INF;

  bfs();

  return dist[n-1][m-1][1] == INF ? -1 : dist[n-1][m-1][1];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++) {
      cin >> board[i][j];
      if (board[i][j] >= 10) {
        teleport[board[i][j]].push_back({i,j});
      }
    }
  }

  cout << solution();
}