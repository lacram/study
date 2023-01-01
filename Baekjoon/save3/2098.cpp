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
#define INF 20000000

using namespace std;

int n,R;
int dp[16][65536];
int dist[16][16];
int visited[16];

int dfs(int now, int route) {

  // 모든 경로 다 방문 했을시 출발지로 돌아가기
  if (route == R) {
    return dist[now][0] == 0 ? INF : dist[now][0];
  }

  int& ret = dp[now][route];
  if (ret != -1) return ret;
  ret = INF;

  for (int next=1; next<n; next++) {
    if (route & (1<<next)) continue;
    if (dist[now][next] == 0) continue;

    ret = min(ret, dfs(next, route | (1<<next)) + dist[now][next]);
  }

  return ret;
}

int solution() {
  R = pow(2,n)-1;

  memset(dp,-1,sizeof(dp));
  
  return dfs(0,1);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++)
      cin >> dist[i][j];
  }

  cout << solution();
}