#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,m;
vector<int> parent;
vector<int> ranking;

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

  cin >> n >> m;

  parent.resize(n+1);
  ranking.resize(n+1);

  for (int i=0; i<=n; i++) 
    parent[i] = i;

  for (int i=0; i<m; i++){
    int a,b,op;
    cin >> op >> a >> b;

    if (op == 0){
      merge(a,b);
    }
    if (op == 1){
      if (find(a) == find(b)) cout << "YES" << endl;
      else cout << "NO" << endl;
    }
  }

}