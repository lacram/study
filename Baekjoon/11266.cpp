#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,m;
int cnt;
int discoverd[10001];
bool isCutVertex[10001];
vector<vector<int>> tree;

int dfs(int now, bool isRoot) {

  discoverd[now] = ++cnt;
  int ret = discoverd[now];
  int child = 0;
  
  for (int next : tree[now]) {
    if (!discoverd[next]) {
      child++;
      int minNode = dfs(next, 0);

      if (!isRoot && minNode >= discoverd[now]) 
        isCutVertex[now] = true;

      ret = min(ret, minNode);
    }
    else
      ret = min(ret, discoverd[next]);
  }
  if (isRoot && child >= 2) 
    isCutVertex[now] = true;

  return ret;
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
    tree[b].push_back(a);
  }

  for (int i=1; i<=n; i++){
    if (!discoverd[i])
      dfs(i,1);
  }

  int cnt = 0;
  vector<int> ans;

  for (int i=1; i<=n; i++){
    if (isCutVertex[i]){
      cnt++;
      ans.push_back(i);
    }
  }

  cout << cnt << endl;
  for (auto a : ans)
    cout << a << " ";
}