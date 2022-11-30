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

int n,m;
vector<int> adj[201];
bool used[201];
int parent[201];

bool dfs(int cow){
  for (int i=0; i<adj[cow].size(); i++){
    int room = adj[cow][i];

    if (used[room]) continue;
    used[room] = true;

    if (parent[room] == -1 || dfs(parent[room])){
      parent[room] = cow;
      return true;
    }
  }
  return false;
}

int solve(){
  int cnt = 0;
  memset(parent, -1 ,sizeof(parent));

  for (int i=0; i<n; i++){
    memset(used, 0, sizeof(used));
    if (dfs(i))
      cnt++;
  }
  return cnt;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  for (int i=0; i<n; i++){
    int a,b;
    cin >> a;
    for (int j=0; j<a; j++){
      cin >> b;
      adj[i].push_back(b);
    }
  }

  cout << solve();
}