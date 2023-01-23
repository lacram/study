#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#define endl '\n'
#define INF 2000000000

using namespace std;

int n,root,q;
vector<vector<int>> tree(100001);
int visited[100001];
int dp[100001];

int dfs(int now) {
  int& ret = dp[now];
  if (ret != -1) return ret;
  ret = 1;

  visited[now] = 1;

  for (auto next : tree[now]) {
    if (visited[next]) continue;
    
    ret += dfs(next);
  }

  return ret;
}

void solution() {
  memset(dp, -1, sizeof(dp));
  // dfs
  dfs(root);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> root >> q;

  for (int i=0; i<n-1; i++){
    int a,b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  solution();

  for (int i=0; i<q; i++) {
    int a;
    cin >> a;
    cout << dp[a] << endl;
  }

}