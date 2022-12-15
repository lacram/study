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

int n,m,r,c;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int visited[10][10];
int board[10][10];
int allDistTotal;

/* 
bfs 큐에 경로 저장
 */

int getDistance(int x1, int y1, int x2, int y2) {
  return abs(x1-x2) + abs(y1-y2);
}

int getDistanceTotal(vector<pair<int,int>> course) {
  int total = allDistTotal;
  for (auto cour : course) {
    int x = cour.first;
    int y = cour.second;

    if (board[x][y]) {
      total -= getDistance(x,y,r,c);
    }
  }
  return total;
}

pair<int,int> bfs() {
  memset(visited, 0, sizeof(visited));
  int ans = INF;
  int minCost = INF;
  // 비용, {이동경로}
  queue<pair<int,vector<pair<int,int>>>> q;

  q.push({0,{{0,0}}});

  while (!q.empty()) {
    int cost = q.front().first;
    vector<pair<int,int>> course = q.front().second;
    int x = course.back().first;
    int y = course.back().second;
    q.pop();

    visited[x][y] = 1;

    if (x == n-1 && y == m-1) {
      ans = min(ans, getDistanceTotal(course));
      minCost = min(minCost, cost);
      continue;
    }

    for (int i=0; i<4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
    
      if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if (!board[nx][ny]) continue;
      if (visited[nx][ny]) continue;

      course.push_back({nx,ny});
      q.push({cost+1,course});
      course.pop_back();
    }
  }

  return {minCost,ans};
}


pair<int,int> solution() {
  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++) {
      if (board[i][j]) {
        allDistTotal += getDistance(r,c,i,j);
      }
    }
  
  return bfs();
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  int test;
  cin >> test;

  for (int t=1; t<=test; t++) {
    cin >> n >> m >> r >> c;
    r--; c--;
    allDistTotal = 0;

    for (int i=0; i<n; i++)
      for (int j=0; j<m; j++) {
        cin >> board[i][j];
      }
    
    pair<int,int> p = solution();
    cout << "#" << t << " " << p.first << " " << p.second << endl;
  }
}