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
int ans = INF;
bool getGift, getDest;
int giftCost, destCost;
pair<int,int> gift;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

/* 
두번까지 방문 가능
 */

void dfs(int cost, int x, int y) {

    // 목적지 
    if (x == n-1 && y== m-1 && getGift) {
      ans = min(ans, cost);
      return;
    }

    // 선물
    if (x == gift.first && y == gift.second) {
      getGift = true;
    }

    for (int i=0; i<4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
    
      if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if (board[nx][ny] == -1) continue;
      if (visited[nx][ny] == 2) continue;

      visited[nx][ny]++;
      dfs(cost,nx,ny);
      visited[nx][ny]--;
    }
    // 텔레포트
    for (auto it=tp.lower_bound(board[x][y]); it!=tp.upper_bound(board[x][y]); it++) {
      int nx = it->second.first;
      int ny = it->second.second;

      if (visited[nx][ny] == 2) continue;

      visited[nx][ny]++;
      dfs(cost+1,nx,ny);
      visited[nx][ny]--;
    }

    if (x == gift.first && y == gift.second) {
      getGift = false;
    }
}

int solution() {
  dfs(0,0,0);

  return ans == INF ? -1 : ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

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