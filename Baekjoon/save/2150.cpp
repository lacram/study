#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <stack>
#define endl '\n'

using namespace std;

int n,m,cnt;
vector<vector<int>> tree;
vector<vector<int>> ans;
int discoverd[10001];
int finished[10001];
stack<int> s;

int dfs(int now){

  int parent = discoverd[now] = ++cnt;
  s.push(now);

  for (auto next : tree[now]){
    if (!discoverd[next]){
      parent = min(parent,dfs(next));
    }
    
    else if (!finished[next]){
      parent = min(parent,discoverd[next]);
    }
  }

  if (parent == discoverd[now]){
    vector<int> scc;
    while (1){
      int a = s.top();
      s.pop();
      scc.push_back(a);
      finished[a] = true;
      if (a == now) break;
    }
    sort(scc.begin(), scc.end());
    ans.push_back(scc);
  }
  return parent;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cin >> n >> m;

  tree.resize(n+1);

  for (int i=0; i<m; i++){
    int a,b;
    cin >> a >> b;
    tree[a].push_back(b);
  }

  for (int i=1; i<=n; i++)
    if (!discoverd[i])
      dfs(i);

  sort(ans.begin(), ans.end());

  cout << ans.size() << endl;

  for (auto scc : ans){
    for (auto a : scc)
      cout << a << " ";
    cout << -1 << endl;
  }
}