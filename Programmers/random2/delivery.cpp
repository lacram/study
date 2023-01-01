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

/* 
다익스트라
 */

vector<pair<int,int>> tree[51];
int dist[51];

void dijkstra() {
  // cost, node
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
  q.push({0,1});

  while (!q.empty()) {
    int cost = q.top().first;
    int now = q.top().second;
    q.pop();

    for (auto node : tree[now]) {
      int next = node.first;
      int ncost = node.second;

      if (dist[next] > dist[now] + ncost) {
        dist[next] = dist[now] + ncost;
        q.push({dist[next], next});
      }
    }
  }
}

int solution(int N, vector<vector<int> > road, int K) {
  fill(dist, dist+51, INF);
  dist[1] = 0;
  
  for (auto r : road) {
    int fr = r[0];
    int to = r[1];
    int cost = r[2];

    tree[fr].push_back({to,cost});
    tree[to].push_back({fr,cost});
  }

  dijkstra();

  int ans = 0;
  for (int i=1; i<=N; i++) {
    if (dist[i] <= K) ans++;
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution(5 ,      {{1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2}}, 3);

}