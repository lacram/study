#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,m;
vector<vector<int>> tree;
int visited[3001];

void dfs(int now){
  visited[now] = 1;

  for (auto next : tree[now]){
    if (visited[next]) continue;
    dfs(next);
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;
  tree.resize(n+1);

  for (int i=1; i<=m; i++){
    int a,b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  int odd=0;

  for (auto node : tree){
    if (node.size() % 2 == 1) odd++;
  }

  // 트리가 한개인지 판별
  dfs(1);
  bool flag = true;
  for (int i=1; i<=n; i++)
    if (!visited[i])
      flag = false;

  if ((odd == 2 || odd == 0) && flag) cout << "YES";
  else cout << "NO";
}