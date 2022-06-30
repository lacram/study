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

/* bfs
출발지에서 도착지까지 경로중 최대값이 최소가 되게
값이 같은시 산봉우리가 작은 것
 */

vector<vector<pair<int,int>>> tree;
vector<bool> isGate;
vector<bool> isSummit;
vector<int> memo;

pair<int,int> bfs(vector<int> gates, vector<int> summits) {
  // 최대값, 현위치
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
  pair<int,int> ans = {INF,INF};
  int check = INF;

  for (auto gate: gates)
    q.push({0,gate});

  while (!q.empty()) {
    int maxCost = q.top().first;
    int now = q.top().second;
    q.pop();

    if (memo[now] < maxCost) continue;
    if (maxCost > check) break;

    // 목적지 도착
    if (isSummit[now]) {
      // 기존보다 낮을 경우에만 갱신
      if (ans.second > now){
        ans = {maxCost,now}; 
        check = maxCost;
      }
      continue;
    }

    for (auto [next,cost] : tree[now]) {
      if (isGate[next]) continue;
      
      int ncost = max(cost,maxCost);
      if (memo[next] <= ncost) continue;

      memo[next] = ncost;
      q.push({ncost,next});
    }
  }

  return ans;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
  tree.resize(n+1);
  isGate.resize(n+1);
  isSummit.resize(n+1);
  memo.resize(n+1);

  for (auto path : paths) {
    int fr = path[0];
    int to = path[1];
    int cost = path[2];

    tree[fr].push_back({to,cost});
    tree[to].push_back({fr,cost});
  }

  for (auto gate : gates) isGate[gate] = 1;
  for (auto summit : summits) isSummit[summit] = 1;
  for (int i=0; i<memo.size(); i++) memo[i] = INF;
  

  pair<int,int> ans = bfs(gates,summits);

  return {ans.second,ans.first};
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution(6, {{1, 2, 3}, {2, 3, 5}, {2, 4, 2}, {2, 5, 4}, {3, 4, 4}, {4, 5, 3}, {4, 6, 1}, {5, 6, 1}}, {1, 3}, {5});

}