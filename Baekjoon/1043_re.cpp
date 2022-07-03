#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <set>
#define endl '\n'

using namespace std;

int n,m,k;
vector<int> parent;
vector<vector<int>> party;
vector<int> ranking;
vector<bool> know;
set<int> knowp;

int find(int u){
  if (u == parent[u]) return u;
  return parent[u] = find(parent[u]);
}

void merge(int u, int v){
  u = find(u);
  v = find(v);

  if (u == v) return;

  if (ranking[u] > ranking[v]) swap(u,v);
  parent[u] = v;
  if (ranking[u] == ranking[v]) ranking[v]++;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m >> k;

  parent.resize(n+1);
  ranking.resize(n+1);
  know.resize(n+1);
  party.resize(m);

  for (int i=1; i<=n; i++)
    parent[i] = i;

  for (int i=0; i<k; i++){
    int a;
    cin >> a;
    know[a] = 1;
  }

  for (int i=0; i<m; i++){
    int a;
    cin >> a;
    party[i].resize(a);
    for (int j=0; j<a; j++){
      cin >> party[i][j];
      merge(party[i][0],party[i][j]);
    }
  }

  for (int i=1; i<=n; i++){
    if (know[i])
      knowp.insert(find(i));
  }

  int ans = 0;

  for (auto p : party){
    bool flag = 1;
    for (auto person : p){
      if (knowp.find(find(person)) != knowp.end()){
        flag = 0;
        break;
      }
    }
    if (flag) ans++;
  }

  cout << ans;
}