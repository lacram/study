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

// n층, m대의 엘리베이터
int n, m;
int parent[101];
vector<pair<int,int>> elevators;
int dist[101];
vector<vector<int>> tree;
vector<int> goals;
vector<int> starts;


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

void print(int num) {
  if (num == -1) return;
  print(parent[num]);
  cout << num+1 << endl;
}

void makeTree() {
  tree.resize(elevators.size());

  for (int i=0; i<elevators.size(); i++)
    for (int j=i+1; j<elevators.size(); j++) {
      if (canGo(i, j)) {
        tree[i].push_back(j);
        tree[j].push_back(i);
      }
    }
}

void bfs() {
  queue<vector<int>> q;

  for (auto start : starts) {
    q.push({start,1});
    dist[start] = 1;
  }

  while (!q.empty()) {
    int now = q.front()[0];
    int cost = q.front()[1];
    q.pop();

    for (auto next : tree[now]) {
      if (dist[next] > cost+1) {
        dist[next] = cost + 1;
        q.push({next,cost+1});
        parent[next] = now; 
      }
    }
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cin >> n >> m;

  for (int i=0; i<m; i++){
    int start, interval;
    cin >> start >> interval;
    elevators.push_back({start, interval});
  }

  int fr,to;
  cin >> fr >> to;

  makeTree();
  starts = getElevator(fr);
  goals = getElevator(to);

  fill(dist, dist + 101, INF);
  memset(parent, -1, sizeof(parent));
  bfs();

  int ans = INF,last;
  for (auto goal : goals) {
    if (ans > dist[goal]) {
      ans = dist[goal];
      last = goal;
    }
  }

  if (ans == INF) cout << -1;
  else {
    cout << ans << endl;
    print(last);
  }
}