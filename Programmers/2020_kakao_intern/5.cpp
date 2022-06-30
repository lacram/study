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
vector<vector<int>> tree;
// 0 선행방 필요x, 1 선행방 필요, 2선행방 필요 & 방문시도함
vector<int> check; 
vector<bool> visited; 
vector<int> need;

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
  tree.resize(n);
  need.resize(n,0);
  check.resize(n,0);
  visited.resize(n,0);

  for (auto p : path){
    tree[p[0]].push_back(p[1]);
    tree[p[1]].push_back(p[0]);
  }

  for (auto o : order){
    if (o[1] == 0) return false;
    need[o[0]] = o[1];
    check[o[1]] = 1;
  }

  // bfs
  queue<int> q;
  q.push(0);
  visited[0] = 1;

  while (!q.empty()){
    int now = q.front();
    q.pop();

    visited[now] = 1;

    // 방문시도하지 않은 방을 뚫었다고 큐에 추가하면 안됨
    int after = need[now];
    if (after && check[after]) {
      if (check[after] == 2) q.push(after);
      check[after] = 0;
    }

    for (int i=0; i<tree[now].size(); i++){
      int next = tree[now][i];
      if (visited[next]) continue;
      if (check[next] == 1) {
        check[next] = 2;
        continue;
      }
      q.push(next);
    }
  }

  for (int i=0; i<n; i++){
    if (!visited[i])
      return false;
  }
  return true;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution(9,{{8,1},{0,1},{1,2},{0,7},{4,7},{0,3},{7,5},{3,6}},{{4,1},{5,2}});

}