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

int n;
int dp[1000001][2];
vector<vector<int>> tmp(1000001);
vector<vector<int>> tree(1000001);
int visited[1000001];


/* 
dp[i][j] : i노드가 루트인 서브트리에서 얼리어답터 유무를 j로 나타냈을 때 최소 얼리어답터의 수
 */

void makeTree(int now) {
  visited[now] = 1;

  for (auto next : tmp[now]) {
    if (visited[next]) continue;

    tree[now].push_back(next);
    makeTree(next);
  }
}

int dfs(int now, int isEarly) {
  int& ret = dp[now][isEarly];
  if (ret != -1) return ret;

  ret = isEarly;

  for (auto next : tree[now]) {
    // 자신이 얼리어답터라면, 자식은 얼리어답터가 아니어도 됨
    if (isEarly) ret += min(dfs(next,0), dfs(next, 1));
    // 자신이 얼리어답터라면, 자식은 항상 얼리어답터이어야 함
    else ret += dfs(next, 1);
  }

  return ret;
}

int solution() {
  // dp 초기화
  memset(dp, -1 ,sizeof(dp));
  // 트리 만들기
  makeTree(1);
  // dfs
  return min(dfs(1,0), dfs(1,1));
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n-1; i++){
    int a,b;
    cin >> a >> b;
    tmp[a].push_back(b);
    tmp[b].push_back(a);
  }

  cout << solution();
}