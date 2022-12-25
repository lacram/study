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
int board[1000][1000];
int visited[1000][1000];
multimap<int,pair<int,int>> tp;
int ans;
bool getGift, getDest;
int giftCost, destCost;
pair<int,int> gift;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

/* 
두번까지 방문 가능
 */

void bfs() {
  // 비용,{x,y}
  queue<pair<int,pair<int,int>>> q;
  q.push({0,{0,0}});
  visited[0][0] = 1;

  while (!q.empty()) {
    int cost = q.front().first;
    int x = q.front().second.first;
    int y = q.front().second.second;
    q.pop();

    // 목적지 
    if (x == n-1 && y== m-1) {
      getDest = true;
      ans += cost;
      continue;
    }

    // 선물
    if (x == gift.first && y == gift.second) {
      getGift = true;
      ans += cost;
    }

    for (int i=0; i<4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
    
      if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if (board[nx][ny] == -1) continue;
      if (visited[nx][ny]) continue;

      visited[nx][ny] = 1;
      q.push({cost,{nx,ny}});
    }
    // 텔레포트
    for (auto it=tp.lower_bound(board[x][y]); it!=tp.upper_bound(board[x][y]); it++) {
      int nx = it->second.first;
      int ny = it->second.second;

      if (visited[nx][ny]) continue;

      visited[nx][ny] = 1;
      q.push({cost+1,{nx,ny}});
    }
  }
}

int solution() {
  bfs();

  if (cnt == 2) return ans;
  return -1;
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

      if (board[i][j] == -2) {
        gift.first = i;
        gift.second = j;
      }
      if (board[i][j] > 0) {
        tp.insert({board[i][j], {i,j}});
      }
    }
  }

  cout << solution();
}