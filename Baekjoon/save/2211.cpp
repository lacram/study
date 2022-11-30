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

using namespace std;

int n,m;
vector<pair<int,int>> cost[1001];
vector<pair<int,int>> ans;

void bfs(){
  vector<int> minCost(n+1, 100000000);
  minCost[1] = 0;
  // 비용 , {prev, now}
  priority_queue<pair<int,pair<int,int>>> pq;
  pq.push({0,{0,1}});

  while (!pq.empty()){
    int c = -pq.top().first;
    int prev = pq.top().second.first;
    int now = pq.top().second.second;
    pq.pop();

    if (c > minCost[now]) continue;

    if (prev != 0) ans.push_back({prev,now});

    for (auto p : cost[now]){
      int next = p.first;
      int nextCost = c+p.second;
      if (nextCost < minCost[next]){
        pq.push({-nextCost,{now,next}});
        minCost[next] = nextCost;
      }
    }
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  for (int i=0; i<m; i++){
    int a,b,c;
    cin >> a >> b >> c;
    cost[a].push_back({b,c});
    cost[b].push_back({a,c});
  } 

  bfs();

  cout << ans.size() << endl;
  for (auto a : ans){
    cout << a.first << " " << a.second << endl;
  }
}