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

/* 
1번이 켜졌을 경우, 1번이 꺼졌을 경우 중 최소
dfs
 */

bool visited[100001];
int dp[2][100001];
vector<vector<int>> tree;
int n;
int ans = INF;

bool checkFin() {
  for (int i=1; i<=n; i++) {
    if (!visited[i]) return false;
  }
  return true;
}

int dfs(bool lightBefore, int now) {
  visited[now] = 1;

  int locateLightCnt = 1;
  int notLocateLightCnt = 0;
  int& ans = dp[lightBefore][now];
  if (ans != -1) return ans;
  
  for (auto next : tree[now]) {
    if (visited[next]) continue;

    // 이전에 등대를 설치했다면
    int a = dfs(true, next);
    int b = dfs(false, next);
    locateLightCnt += a;
    notLocateLightCnt += b;
  }
  visited[now] = 0;

  // 이번에는 등대를 설치해도 안해도 됨
  if (lightBefore) {
    ans = min(locateLightCnt, notLocateLightCnt);
  } else {
    ans = locateLightCnt;
  }

  return ans;
}

int solution(int N, vector<vector<int>> lighthouse) {
  n = N;
  tree.resize(n+1);
  vector<int> check(n+1);
  memset(dp, -1, sizeof(dp));

  for (auto l : lighthouse) {
    int a = l[0];
    int b = l[1];

    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  return min(dfs(true,1), dfs(false,1));
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  // cout << solution(10, {{4, 1}, {5, 1}, {5, 6}, {7, 6}, {1, 2}, {1, 3}, {6, 8}, {2, 9}, {9, 10}});
  cout << solution(4 , {{1, 2}, {1, 3}, {1, 4}});

}