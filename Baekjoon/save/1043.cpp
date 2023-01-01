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
vector<bool> know(51);
vector<int> parent(51);
vector<vector<int>> arr;

int find(int u){
  if (u == parent[u]) return u;
  parent[u] = find(parent[u]);
  if (know[u]) know[parent[u]] = 1;
  if (know[parent[u]]) know[u] = 1;

  return parent[u];
}

void merge(int u, int v){
  u = find(u);
  v = find(v);

  if (u == v) return;

  if (know[u]) know[v] = 1;
  if (know[v]) know[u] = 1;
  parent[v] = u;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;
  cin >> k;

  for (int i=0; i<k; i++){
    int a;
    cin >> a;
    know[a] = 1;
  }

  arr.resize(m);
  for (int i=0; i<m; i++){
    int t;
    cin >> t;
    arr[i].resize(t);
    for (int j=0; j<t; j++)
      cin >> arr[i][j];
  }
  
  for (int i=1; i<=n; i++)
    parent[i] = i;

  for (int i=0; i<arr.size(); i++){
    int p = arr[i][0];
    for (int j=0; j<arr[i].size(); j++)
      merge(p,arr[i][j]);
  }

  int ans = 0;
  for (int i=1; i<=n; i++)
    find(i);

  for (int i=0; i<arr.size(); i++){
    bool flag = 1;
    for (int j=0; j<arr[i].size(); j++)
      if (know[arr[i][j]]){
        flag = 0;
        break;
      }
    if (flag) ans++;
  }

  cout << ans;
}