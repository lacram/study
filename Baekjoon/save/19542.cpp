#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,s,d;
vector<vector<int>> tree;
int dp[100001];

int getMaxDepth(int root, int parent){
  int &ret = dp[root];
  if (ret != -1) return ret;
  ret = 0;

  for (int i=0; i<tree[root].size(); i++){
    if (tree[root][i] == parent) continue;
    ret = max(ret, getMaxDepth(tree[root][i],root));
  }
  ret++;

  return ret;
}

int solve(int root, int parent){

  int ret = 0;

  for (int i=0; i<tree[root].size(); i++){
    if (tree[root][i] == parent) continue;
    if (getMaxDepth(tree[root][i],root) <= d) continue;

    ret += solve(tree[root][i],root)+1;
  }

  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> s >> d;
  tree.resize(n+2);

  for (int i=0; i<n-1; i++){
    int a,b;
    cin >> a >> b;

    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  memset(dp, -1, sizeof(dp));

  cout << solve(s,-1)*2;
}