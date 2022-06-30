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

map<int,int> mapping;
vector<vector<int>> trees;
vector<vector<int>> costs;
vector<vector<int>> Tcosts;
int dist[1001][1025];
int isTrap[1001];
int ans = INF;

int dijkstra(int start, int end){
  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
  pq.push({0,start,0});

  while (!pq.empty()){
    int cost = pq.top()[0];
    int now = pq.top()[1];
    int state = pq.top()[2];
    pq.pop();

    if (dist[now][state] < cost) continue;

    if (now == end){
      return cost;
    }
    
    int nowState = 0;
    if (isTrap[now]) nowState = (state & (1 << mapping[now])) ? 1 : 0;

    vector<vector<int>> Ncosts;
    for (auto next : trees[now]){
      int nextState = 0;
      int nState = state;

      if (isTrap[next]) {
        nextState = (state & (1 << mapping[next])) ? 1 : 0;
        nState = state ^ (1 << mapping[next]);
      }

      if ((nowState && !nextState) || (!nowState && nextState)) Ncosts = Tcosts;
      else Ncosts = costs;

      int nextDist = cost + Ncosts[now][next];
      
      if (dist[next][nState] > nextDist) {
        dist[next][nState] = nextDist;
        pq.push({nextDist, next, nState});
      }
    }
  }
  return -1;
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
  int idx = 0;
  for (auto t : traps) {
    isTrap[t] = 1;
    mapping[t] = idx++;
  }
  costs.resize(n+1);
  Tcosts.resize(n+1);
  trees.resize(n+1);

  for (int i=0; i<=n; i++){
    costs[i].resize(n+1,INF);
    Tcosts[i].resize(n+1,INF);
    for (int j=0; j<1025; j++)
      dist[i][j] = INF;
  }
  
  for (auto road: roads){
    int fr = road[0];
    int to = road[1];
    int cost = road[2];
    trees[fr].push_back(to);
    trees[to].push_back(fr);
    costs[fr][to] = min(costs[fr][to], cost);
    Tcosts[to][fr] = min(Tcosts[to][fr], cost);
  }

  for (int i=0; i<trees.size(); i++){
    sort(trees[i].begin(), trees[i].end());
    trees[i].erase(unique(trees[i].begin(), trees[i].end()), trees[i].end());
  }

  return dijkstra(start,end);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution(5,1,	5,	{{1, 2, 1}, {2, 3, 1}, {3, 2, 1}, {3, 5, 1}, {1, 5, 10}},	{3});

}