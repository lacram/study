#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,test,k;
int workingTime[1000];
int totalTime[1000];
int visited[1000];
int last;
vector<int> sorted;
vector<vector<int>> tree;
vector<vector<int>> parent;

void dfs(int now){
  visited[now] = 1;

  for (int i=0; i<tree[now].size(); i++)
    if (!visited[tree[now][i]])
      dfs(tree[now][i]);

  sorted.push_back(now);
}

int solve(){
  
  for (auto work : sorted){
    int ret = 0;
    for (auto before : parent[work])
      ret = max(ret, workingTime[before]);
    totalTime[work] = ret + workingTime[work];
  }

  return totalTime[last];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cin >> test;

  while (test--){
    cin >> n >> k;

    for (int i=0; i<n; i++)
      cin >> workingTime[i];

    tree.resize(n);
    parent.resize(n);
    int f;
    for (int i=0; i<k; i++){
      int a,b;
      cin >> a >> b;
      a--,b--;
      if (i == 0) f = a;
      parent[b].push_back(a);
      tree[a].push_back(b);
    }
    cin >> last;
    last--;

    dfs(f);
    cout << solve() << endl;
  }
}