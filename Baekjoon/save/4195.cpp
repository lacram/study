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
vector<int> parent(200000);
vector<int> ranking(200000);
vector<int> psize(200000);
map<string,int> m;

int find(int u){
  if (u == parent[u]) return u;
  return parent[u] = find(parent[u]);
}

int merge(int u, int v){
  u = find(u);
  v = find(v);

  if (u == v) return psize[u];

  if (ranking[u] > ranking[v]) swap(u,v);
  if (ranking[u] == ranking[v]) ranking[v]++;
  parent[u] = v;

  return psize[v] += psize[u];
}

int getPos(string str){
  if (m.find(str) != m.end()) return m.find(str)->second;
  return -1;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cin >> test;

  while (test--){
    cin >> n;

    for (int i=0; i<n*2; i++){
      parent[i] = i;
      psize[i] = 1;
    }
    int pos = 0;

    for (int i=0; i<n; i++){
      string a,b;
      cin >> a >> b;
      int c = getPos(a);
      int d = getPos(b);
      if (c == -1){
        m[a] = pos;
        c = pos++;
      }
      if (d == -1){
        m[b] = pos;
        d = pos++;
      }

      cout << merge(c,d) << endl;
    }
  }

}