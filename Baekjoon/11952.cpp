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

int n,roadN,zombieN,range,p,q;
bool zombie[100001];
bool nearZombie[100001];
map<pair<int,int>,int> cost;
vector<vector<int>> road;

void checkDanger(){
  // 좀비마을, 범위
  queue<pair<int,int>> q;
  for (int i=0; i<=n; i++)
    if (zombie[i])
      q.push({i,range});
  
  while (!q.empty()){
    int now = q.front().first;
    int r = q.front().second;
    q.pop();

    if (r <= 0) continue;

    for (auto next : road[now]){
      if (zombie[next] || nearZombie[next]) continue;
      nearZombie[next] = 1;
      q.push({next,r-1});
    }
  }
}

long long bfs(){
  vector<long long> minCost(n+1,10000000000000);
  priority_queue<pair<long long,int>> pq;
  pq.push({0,1});

  while(!pq.empty()){
    long long c = -pq.top().first;
    int now = pq.top().second;
    pq.pop();

    if (c > minCost[now]) continue;

    for (auto next : road[now]){
      if (zombie[next]) continue;

      long long nextC = c+cost[{now,next}];
      if (nextC < minCost[next]){
        minCost[next] = nextC;
        pq.push({-nextC,next});
      }
    }
  }
  return minCost[n];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> roadN >> zombieN >> range >> p >> q;

  road.resize(n+1);

  for (int i=0; i<zombieN; i++){
    int a;
    cin >> a;
    zombie[a] = 1;
  }

  for (int i=0; i<roadN; i++){
    int a,b;
    cin >> a >> b;
    cost[{a,b}] = p;
    cost[{b,a}] = p;
    road[a].push_back(b);
    road[b].push_back(a);
  }

  checkDanger();

  for (int i=0; i<=n; i++){
    for (int j=0; j<road[i].size(); j++){
      // 좀비 마을로 갈때 숙박비 q
      if (nearZombie[road[i][j]])
        cost[{i,road[i][j]}] = q;
      // 도착지 갈때 숙박비 0
      if (road[i][j] == n){
        cost[{i,road[i][j]}] = 0;
      }
    }
  }
  cout << bfs();
}