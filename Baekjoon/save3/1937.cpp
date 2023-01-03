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
int board[500][500];
int dp[500][500];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

// x,y에서 시작하여 이동할 수 있는 최댓값
int dfs(int x, int y) {

  int& ret = dp[x][y];
  if (ret != -1) return ret;
  ret = 1;

  for (int i=0; i<4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
  
    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
    if (board[nx][ny] <= board[x][y]) continue;

    ret = max(ret, dfs(nx,ny)+1);
  }

  return ret;
}

int solution() {
  memset(dp,-1,sizeof(dp));

  int ans = 0;
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) {
      ans = max(ans, dfs(i,j));
    }
  
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++)
      cin >> board[i][j];
  }

  cout << solution();
}