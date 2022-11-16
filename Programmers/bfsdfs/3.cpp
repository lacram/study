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

int visited[200];
vector<vector<int>> tree;

void dfs(int root) {
  visited[root] = 1;

  for (auto node : tree[root]) {
    if (visited[node]) continue;
    dfs(node);
  }
}

int solution(int n, vector<vector<int>> computers) {
  int ans = 0;
  tree.resize(n);

  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      if (i == j) continue;
      if (computers[i][j]) tree[i].push_back(j);
    }
  }

  for (int i=0; i<n; i++) {
    if (visited[i]) continue;
    dfs(i);
    ans++;
  }

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}