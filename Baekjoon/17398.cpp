#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,m,q;
vector<pair<int,int>> v(100000);
vector<int> rm(100000);
vector<int> memo(100001);
vector<int> parent(100001);
vector<int> psize(100001);

int find(int u){
  if (u == parent[u]) return u;
  return parent[u] = find(parent[u]);
}

int merge(int u, int v){
  u = find(u);
  v = find(v);

  if (u == v) return 0;

  parent[u] = v;
  int ret = psize[v] * psize[u];
  psize[v] += psize[u];
  return ret;
}

void connect(){
  for (int i=0; i<v.size(); i++){
    if (memo[i]) continue;
    
    merge(v[i].first,v[i].second);
  }
}

long long solve(){
  connect();

  long long ans = 0;

  // 역순으로 연결
  for (int i=rm.size()-1; i>=0; i--){
    pair<int,int> p = v[rm[i]];
    ans += merge(p.first,p.second);
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m >> q;

  for (int i=0; i<m; i++){
    int a,b;
    cin >> a >> b;
    v[i] = {a,b};
  }
  for (int i=0; i<q; i++){
    cin >> rm[i];
    rm[i]--;
    memo[rm[i]] = 1;
  }
  
  for (int i=1; i<=n; i++)
    parent[i] = i;
  for (int i=1; i<=n; i++)
    psize[i] = 1;

  cout << solve();
}