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

int n,m,k;

vector<int> plant;
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

  cin >> n >> m >> k;

  parent.resize(n+1);

  for (int i=0; i<k; i++){
    int a;
    cin >> a;
    plant.push_back(a); 
  }

  // 입력
  for (int i=0; i<m; i++){
    int a,b,c;
    cin >> a >> b >> c;
    adj.push_back({c,{a,b}});
  }

  // 초기세팅
  for (int i=1; i<=n; i++)
    parent[i] = i;
  
  // 0번 도시부터 발전소까지 비용 0
  for (int i=0; i<k; i++){
    adj.push_back({0,{0,plant[i]}});
  }
  
  sort(adj.begin(), adj.end());
  
  cout << solve();
}