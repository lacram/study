#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <map>
#define endl '\n'

using namespace std;

int n,test;
vector<int> parent;
vector<int> ranking;
vector<int> psize;
map<string,int> m;

int find(int u){
  if (u == parent[u]) return u;
  return parent[u] = find(parent[u]);
}

int merge(int u, int v){
  u = find(u);
  v = find(v);

  if (u == v) return psize[v];

  if (ranking[u] > ranking[v]) swap(u,v);
  if (ranking[u] == ranking[v]) ranking[v]++;
  parent[u] = v;
  return psize[v] += psize[u];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> test;

  while (test--){
    cin >> n;

    parent.clear();
    ranking.clear();
    psize.clear();
    m.clear();
    parent.resize(n*2);
    ranking.resize(n*2);
    psize.resize(n*2);

    for (int i=0; i<n*2; i++) {
      parent[i] = i;
      psize[i] = 1;
    }
    
    int pos = 0;

    for (int i=0; i<n; i++){
      string n1,n2;
      int p1,p2;
      cin >> n1 >> n2;

      if (m.find(n1) != m.end()) p1 = m[n1];
      else {
        p1 = pos++;
        m[n1] = p1;
      }
      if (m.find(n2) != m.end()) p2 = m[n2];
      else {
        p2 = pos++;
        m[n2] = p2;
      }

      cout << merge(p1,p2) << endl;
    }

  }
}