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

int n;

vector<pair<double,double>> point;
vector<pair<double,pair<int,int>>> dis;
vector<int> parent(101);

int find(int u){
  if (parent[u] == u) return u;
  return parent[u] = find(parent[u]);
}

void merge(int u, int v){
  u = find(u);
  v = find(v);

  parent[v] = u;
}

double solve(){
  double ans = 0;
  for (auto d: dis){
    double cost = d.first;
    int u = d.second.first;
    int v = d.second.second;

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
  cout.precision(3);

  cin >> n;

  for (int i=0; i<n; i++){
    double a,b;
    cin >> a >> b;
    point.push_back({a,b});
  }
  
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      if (i == j) continue;
      double d = pow((point[i].first-point[j].first),2) + pow((point[i].second-point[j].second),2);
      dis.push_back({sqrt(d),{i,j}});
    }
  }
  
  for (int i=0; i<n; i++)
    parent[i] = i;

  sort(dis.begin(), dis.end());

  cout << solve();
}