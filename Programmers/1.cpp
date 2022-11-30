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
#define INF 1000000

using namespace std;

// n층, m대의 엘리베이터
int n, m;
int parent[101];
vector<pair<int,int>> elevators;
int dist[101];
vector<vector<int>> tree;
vector<int> goals;
vector<int> starts;

int dp[101][101];
int record[101][101];

/* 
bfs
 */

bool canGo(int a, int b) {
  int start = elevators[a].first;
  int interval = elevators[a].second;
  int start2 = elevators[b].first;
  int interval2 = elevators[b].second;

  for (int floor=start2; floor<=n; floor+=interval2) {
    if (floor >= start && ((floor-start) % interval) == 0) {
      return true;
    }
  }
  return false;
}

vector<int> getElevator(int floor) {
  vector<int> v;
  for (int j=0; j<m; j++) {
    int start = elevators[j].first;
    int interval = elevators[j].second;

    for (int i=start; i<=n; i+=interval) {
      if (i == floor) v.push_back(j);
    }
  }
  return v;
}

void print(pair<int,int> p) {
  if (record[p.first][p.second] == -1) return;
  print({p.first, record[p.first][p.second]});
  cout << record[p.first][p.second]+1 << endl;
  print({record[p.first][p.second], p.second});
}

void makeTree() {
  tree.resize(elevators.size());

  for (int i=0; i<elevators.size(); i++)
    for (int j=i+1; j<elevators.size(); j++) {
      if (canGo(i, j)) {
        dp[i][j] = 1;
        dp[j][i] = 1;
      }
    }
}

void sol() {
  
  for (int k=0; k<m; k++)
    for (int i=0; i<m; i++)
      for (int j=0; j<m; j++) {
        if (dp[i][j] > dp[i][k] + dp[k][j]) {
          dp[i][j] = dp[i][k] + dp[k][j];
          record[i][j] = k;
        }
      }
  
  int ans = INF;
  pair<int,int> p;
  for (auto start : starts) {
    for (auto goal : goals) {
      if (ans > dp[start][goal]) {
        ans = dp[start][goal];
        p = {start,goal};
      }
    }
  }
  if (ans == INF) {
    cout << -1;
    return;
  }

  cout << ans+1 << endl;
  cout << p.first+1 << endl;
  print(p);
  cout << p.second+1 << endl;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  for (int i=0; i<m; i++){
    int start, interval;
    cin >> start >> interval;
    elevators.push_back({start, interval});
  }

  int fr,to;
  cin >> fr >> to;

  for (int i=0; i<m; i++)
    for (int j=0; j<m; j++){
      if (i == j) dp[i][j] = 0;
      else dp[i][j] = INF;
    }

  makeTree();
  starts = getElevator(fr);
  goals = getElevator(to);

  fill(dist, dist + 101, INF);
  memset(record, -1, sizeof(record));

  sol();
}