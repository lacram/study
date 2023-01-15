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

int n,m;
int board[1000][1000];
int visited[1000][1000];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void dfs(int x, int y) {
  visited[x][y] = 1;
  
  for (int i=0; i<4; i++) {
    int nx = (x + dx[i] + n) % n;
    int ny = (y + dy[i] + m) % m;

    if (visited[nx][ny]) continue;
    if (board[nx][ny]) continue;

    dfs(nx,ny);
  }
}

int solution() {
  int ans = 0;
  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++) {
      if (!visited[i][j] && !board[i][j]) {
        dfs(i,j);
        ans++;
      }
    }
  
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++) {
      cin >> board[i][j];
    }
  }

  cout << solution();
}