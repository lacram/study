#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,m;
vector<int> visited;
vector<vector<int>> tree;
vector<int> sorted;

void dfs(int now){
  visited[now] = 1;

  for (auto node : tree[now]){
    if (visited[node]) continue;
    dfs(node);
  }

  sorted.push_back(now);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  visited.resize(n+1);
  tree.resize(n+1);

  for (int i=0; i<m; i++){
    int a,b;
    cin >> a >> b;
    
    tree[a].push_back(b);
  }

  for (int i=1; i<=n; i++)
    if (!visited[i])
      dfs(i);
  
  reverse(sorted.begin(), sorted.end());
  
  for (auto a : sorted)
    cout << a << " ";
}