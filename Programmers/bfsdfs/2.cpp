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

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int visited[100][100];
int n,m;

int bfs(vector<vector<int>> maps) {
  // {이동횟수,x,y}
  queue<vector<int>> q;

  q.push({1,0,0});
  visited[0][0] = 1;

  while(!q.empty()) {
    int cnt = q.front()[0];
    int x = q.front()[1];
    int y = q.front()[2];
    q.pop();

    if (x == n-1 && y == m-1) return cnt;

    for (int i=0; i<4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
    
      if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if (!maps[nx][ny]) continue;
      if (visited[nx][ny]) continue;

      visited[nx][ny] = 1;
      q.push({cnt+1,nx,ny});
    }
  }

  return -1;
}

int solution(vector<vector<int> > maps) {
  n = maps.size();
  m = maps[0].size();

  return bfs(maps);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  vector<vector<int>> m;
  vector<int> v;

  for (int i=0; i<100; i++)
    v.push_back(1);
  for (int i=0; i<100; i++)
    m.push_back(v);
    

  cout << solution(m);

}