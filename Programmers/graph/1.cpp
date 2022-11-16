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

int ans;
int maxCnt;
vector<vector<int>> tree;
int visited[20001];

// bfs로 탐색
void bfs() {
  // 현위치, 거리
  queue<pair<int,int>> q;
  q.push({1,0});
  visited[1] = 1;

  while (!q.empty()) {
    int now = q.front().first;
    int cnt = q.front().second;
    q.pop();

    if (maxCnt <= cnt) {
      if (maxCnt < cnt) {
        maxCnt = cnt;
        ans = 0;
      }
      ans++;
    }

    for (auto next : tree[now]) {
      if (visited[next]) continue;

      visited[next] = 1;
      q.push({next,cnt+1});
    }
  }
}


int solution(int n, vector<vector<int>> edge) {
  tree.resize(n+1);
  
  for (auto e : edge) {
    tree[e[0]].push_back(e[1]);
    tree[e[1]].push_back(e[0]);
  }

  bfs();

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution(6, {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}});

}