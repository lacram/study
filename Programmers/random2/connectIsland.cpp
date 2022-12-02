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

/* 
작은 경로부터 선택
사이클이 생성되면 선택 취소
분리집합
 */

int parent[101];

int getParent(int u) {
  if (u == parent[u]) return u;
  return parent[u] = getParent(parent[u]);
}

void merge(int u, int v) {
  u = getParent(u);
  v = getParent(v);

  if (u < v) parent[v] = u;
  else parent[u] = v;
}

bool isCycle(int u, int v) {
  if (getParent(u) == getParent(v)) return true;
  return false;
}

bool compare(vector<int> v1, vector<int> v2) {
  return v1[2] < v2[2];
}

int solution(int n, vector<vector<int>> costs) {
  for (int i=1; i<=n; i++) {
    parent[i] = i;
  }

  sort(costs.begin(), costs.end(), compare);

  int ans = 0;
  for (auto cost: costs) {
    int u = cost[0];
    int v = cost[1];
    int cnt = cost[2];

    if (isCycle(u,v)) continue;
    
    ans += cnt;
    merge(u,v);
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution(4, {{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}});

}