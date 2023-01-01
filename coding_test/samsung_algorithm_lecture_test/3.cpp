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

int n, m, k;
int ans;
int dest[101][101];
char board[101][101];
int dist[101][101][101][101];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<pair<int,int>> destination;

/* 
bfs

 */

vector<int> getSide() {
  int up = INF;
  int down = 0;
  int right = 0;
  int left = INF;

  for (auto d : destination) {
    up = min(up, d.first);
    down = max(down, d.first);
    left = min(left, d.second);
    right = max(right, d.second);
  }
  return {right,down,left,up};
}

int bfs(int a, int b) {
  // {cost,{x,y}}
  queue<pair<int,pair<int,int>>> q;
  int maxDest = 0;
  int visited[101][101] = {};
  int cnt = 0;

  q.push({0,{a,b}});
  visited[a][b] = 1;

  while (!q.empty()) {
    int cost = q.front().first;
    int x = q.front().second.first;
    int y = q.front().second.second;
    q.pop();

    if (dest[x][y]) {
      maxDest = max(maxDest, cost);
      cnt++;
    }
    if (cnt == k) {
      return maxDest;
    }
    if (cost > ans) break;

    for (int i=0; i<4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
    
      if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
      if (board[nx][ny] == '#') continue;
      if (visited[nx][ny]) continue;

      visited[nx][ny] = 1;
      q.push({cost+1,{nx,ny}});
    }
  }

  return maxDest && (cnt == k) ? maxDest : INF;
}

int solution() {
  ans = INF;
  vector<int> v = getSide();
  int up = v[3];
  int down = v[1];
  int right = v[0];
  int left = v[2];
  // cout << right << " " << down << " " << left << " " << up << " " << endl;
  for (int i=up; i<=down; i++)
    for (int j=left; j<=right; j++) {
      if (board[i][j] != '#') {
        ans = min(ans, bfs(i,j));
      }
    }

  return ans == INF ? -1 : ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  int test;
  cin >> test;

  for (int t=1; t<=test; t++) {
    cin >> n >> m >> k;

    memset(dest, 0, sizeof(dest));
    destination.clear();

    for (int i=1; i<=n; i++)
      for (int j=1; j<=m; j++) {
        cin >> board[i][j];
      }
    
    for (int i=0; i<k; i++) {
      int a,b;
      cin >> a >> b;
      dest[a][b] = 1;
      destination.push_back({a,b});
    }

    cout << "#" << t << " " << solution() << endl;
  }
}