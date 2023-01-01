#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <set>
#define endl '\n'

using namespace std;

int n,m;
vector<int> parent(501);
vector<int> ranking(501);
vector<bool> cycle(501);

int find(int u){
  if (u == parent[u]) return u;
  return parent[u] = find(parent[u]);
}

void merge(int u, int v){
  u = find(u);
  v = find(v);

  if (u == v) {
    cycle[u] = 1;
    return;
  }
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

  int test = 0;

  while (1){
    test++;
    cin >> n >> m;
    if (n == 0 && m == 0) break;

    for (int i=1; i<=n; i++){
      parent[i] = i;
      ranking[i] = 0;
      cycle[i] = 0;
    }

    for (int i=0; i<m; i++){
      int a,b;
      cin >> a >> b;

      merge(a,b);
    }
    set<int> s;

    for (int i=1; i<=n; i++)
      s.insert(find(i));

    int ans = 0;

    for (auto a : s)
      if (!cycle[a])
        ans++;

    cout << "Case " << test << ": ";
    if (ans == 0) cout << "No trees." << endl;
    else if (ans == 1) cout << "There is one tree." << endl;
    else cout << "A forest of " << ans << " trees." << endl;
  }

}