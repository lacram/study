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

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int dp[25][25][4];
int visited[25][25];
vector<vector<int>> b;
int n;
int res = INF;

void dfs(int x, int y, int last, int curCost){
  if (dp[x][y][last] < curCost) return;
  dp[x][y][last] = curCost;

  if (x == n-1 && y == n-1) {
    res = min(res, curCost);
  }

  for (int i=0; i<4; i++){
    int nx = x+dx[i];
    int ny = y+dy[i];

    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
    if (b[nx][ny] == 1) continue;
    if (visited[nx][ny]) continue;

    visited[nx][ny] = 1;
    int cost = 600;
    if (last == i || (x==0 && y==0)) cost = 100;

    dfs(nx,ny,i,curCost+cost);

    visited[nx][ny] = 0;
  }
}

int solution(vector<vector<int>> board) {
  b = board;
  n = board.size();

  memset(visited, 0, sizeof(visited));
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) 
      for (int k=0; k<4; k++) {
        dp[i][j][k] = INF;
      }

  dfs(0,0,0,0);

  return res;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution({{0, 0, 0, 0, 0}, {0, 1, 1, 1, 0}, {0, 0, 1, 0, 0}, {1, 0, 0, 0, 1}, {0, 1, 1, 0, 0}});
  cout << 'a';
}