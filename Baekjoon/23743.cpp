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

int n,m;

vector<int> parent;
// {비용, {u,v}}
vector<pair<int,pair<int,int>>> adj;

int find(int u){
  if (u == parent[u]) return u;
  return parent[u] = find(parent[u]);
}

void merge(int u, int v){
  u = find(u);
  v = find(v);

  if (u == v) return;

  parent[v] = u;
}

int solve(){
  int ans = 0;

  for (auto a : adj) {
    int cost = a.first;
    int u = a.second.first;
    int v = a.second.second;

    // 사이클 형성될 경우
    if (find(u) == find(v)) continue;

    merge(u,v);
    ans += cost;
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  parent.resize(n+1);

  // 입력
  for (int i=0; i<m; i++){
    int a,b,c;
    cin >> a >> b >> c;
    adj.push_back({c,{a,b}});
  }

  for (int i=1; i<=n; i++){
    int a;
    cin >> a;
    adj.push_back({a,{0,i}});
  }

  // 초기세팅
  for (int i=1; i<=n; i++)
    parent[i] = i;
  
  sort(adj.begin(), adj.end());
  
  cout << solve();
}