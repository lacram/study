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
char board[101][101];
//dangers의 idx,x,y
int dist[101][101][101];
vector<pair<int,int>> dangers;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

/* 
인화물질로 부터 다익스트라

 */

void dijkstra() {
  for (int i=0; i<k; i++)
    for (int j=0; j<n; j++)
      for (int t=0; t<m; t++) {
        dist[i][j][t] = INF;
      }
      
  queue<vector<int>> q;

  for (int i=0; i<dangers.size(); i++) {
    int x = dangers[i].first;
    int y = dangers[i].second;
    q.push({0,i,x,y});
  }

  while (!q.empty()) {
    int cost = q.front()[0];
    int idx = q.front()[1];
    int x = q.front()[2];
    int y = q.front()[3];
    q.pop();

    for (int i=0; i<4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
    
      if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if (board[nx][ny] == '#') continue;

      if (dist[idx][nx][ny] > cost+1) {
        dist[idx][nx][ny] = cost+1;
        q.push({cost+1,idx,nx,ny});
      }
    }
  }
}

int solution() {
  dijkstra();

  int ans = INF;
  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++) {
      if (board[i][j] == '#') continue;
      // 한 점에 대해서 인화 물질까지 거리 최대 구하기
      int maxDist = 0;
      for (int t=0; t<k; t++) {
        maxDist = max(maxDist, dist[t][i][j]); 
      }
      ans = min(ans, maxDist);
    }

  return ans == INF ? -1 : ans;
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
    cin >> n >> m >> k;
    dangers.clear();

    for (int i=0; i<n; i++)
      for (int j=0; j<m; j++) {
        cin >> board[i][j];
      }
    
    for (int i=0; i<k; i++) {
      int a,b;
      cin >> a >> b;
      dangers.push_back({a-1,b-1});
    }

    cout << "#" << t << " " << solution() << endl;
  }
}