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
vector<vector<int>> sccarr;
vector<int> ans;
int discoverd[100001];
int finished[100001];
int visited[100001];
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
    sccarr.push_back(scc);
  }
  return parent;
}

void dfs2(int now){
  visited[now] = 1;
  for (auto next : tree[now]){
    if (visited[next]) continue;
    dfs2(next);
  }
}

void solve(){
  for (auto scc : sccarr){
    for (int i=0; i<n; i++)
      visited[i] = 0;

    dfs2(scc[0]);

    bool flag = 1;
    for (int i=0; i<n; i++)
      if (!visited[i]){
        flag = 0;
        break;
      }
    if (flag)
      for (auto s : scc)
        ans.push_back(s);
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  int test;
  cin >> test;

  while (test--){
    cin >> n >> m;

    tree.clear();
    tree.resize(n);
    sccarr.clear();
    ans.clear();
    for (int i=0; i<n; i++)
      discoverd[i] = 0;
    for (int i=0; i<n; i++)
      finished[i] = 0;

    for (int i=0; i<m; i++){
      int a,b;
      cin >> a >> b;
      tree[a].push_back(b);
    }

    for (int i=0; i<n; i++)
      if (!discoverd[i])
        dfs(i);

    solve();

    if (ans.empty()) cout << "Confused" << endl;
    else{
      for (auto a : ans)
        cout << a << endl;
    }
    cout << endl;
  }
}