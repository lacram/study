#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
// #include <fstream>
#define endl '\n'
#define INF 2000000000
 
using namespace std;
 
int n;
int board[12][12];
pair<int,int> ans;
vector<pair<int,int>> cells;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
 
/* 
완탐 
dfs
 */
 
void updateAns(int cnt, int cost) {
  if (ans.first < cnt) ans = {cnt,cost};
  else if (ans.first == cnt) ans.second = min(cost, ans.second);
}

int check(int x, int y, int dir) {
  int cnt = 0;

  while (1) {
    x += dx[dir];
    y += dy[dir];

    if (x < 0 || y < 0 || x >= n || y >= n) break;
    if (board[x][y]) return 0;

    cnt++;
  }

  return cnt;
}

void dfs(int depth, int cnt, int cost) {
 
  if (depth == cells.size()) {
    updateAns(cnt, cost);
    return;
  }
 
  int x = cells[depth].first;
  int y = cells[depth].second;
  for (int i=0; i<4; i++) {
    int nx = x;
    int ny = y;
    int ncost = check(x,y,i);

    if (ncost == 0) continue;

    // 전원 연결
    while (1) {
      nx += dx[i];
      ny += dy[i];
      if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;
      board[nx][ny] = 1;
    }
 
    dfs(depth+1, cnt + 1, cost + ncost);
 
    // 전원 연결 해제
    while (1) {
      nx -= dx[i];
      ny -= dy[i];
      if (nx == x && ny == y) break;
      board[nx][ny] = 0;
    }
  }

  // 연결안함
  dfs(depth+1, cnt, cost);
}
 
int solution() {
  dfs(0,0,0);
 
  return ans.second;
}
 
int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  // ifstream cin;
  // cin.open("input.txt");
 
  int test;
  cin >> test;
 
  for (int k=1; k<=test; k++) {
    ans = {0,INF};
    cells.clear();
 
    cin >> n;
    for (int i=0; i<n; i++){
      for (int j=0; j<n; j++) {
        cin >> board[i][j];
        if (board[i][j]) {
          if (i == 0 || j == 0 || i == n-1 || j == n-1) continue;
          cells.push_back({i,j});
        }
      }
    }
    cout << "#" << k << " " << solution() << endl;
  }
 
}