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

int n,m,k,ans;
vector<vector<int>> board(100, vector<int>(100));

/* 
dfs로 모든 방향으로 밀어보기

 */

int getMaxPeople() {
  int cnt = 0;
  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++) {
      cnt = max(cnt, board[i][j]);
    }
  return cnt;
}

// ->
void eastWind() {
  for (int i=0; i<n; i++) {
    bool flag = false;
    for (int j=m-1; j>0; j--) {
      // 사람을 만났다면 민다
      if (board[i][j]) {
          board[i][j-1] += board[i][j];
          board[i][j] = 0;
          flag = true;
        }
      if (flag) break;
      }
  }
}

// ->
void westWind() {
  for (int i=0; i<n; i++) {
    bool flag = false;
    for (int j=0; j<m-1; j++) {
      // 사람을 만났다면 민다
      if (board[i][j]) {
          board[i][j+1] += board[i][j];
          board[i][j] = 0;
          flag = true;
        }
      if (flag) break;
      }
  }
}

// 위로 밀기
void southWind() {
  for (int i=0; i<m; i++) {
    bool flag = false;
    for (int j=n-1; j>0; j--) {
      // 사람을 만났다면 민다
      if (board[j][i]) {
          board[j-1][i] += board[j][i];
          board[j][i] = 0;
          flag = true;
        }
      if (flag) break;
    }
  }
}

// 아래로 밀기
void northWind() {
  for (int i=0; i<m; i++) {
    bool flag = false;
    for (int j=0; j<n-1; j++) {
      // 사람을 만났다면 민다
      if (board[j][i]) {
          board[j+1][i] += board[j][i];
          board[j][i] = 0;
          flag = true;
        }
      if (flag) break;
    }
  }
}

void dfs(int depth) {
  if (depth == k) {
    ans = max(ans, getMaxPeople());
    return;
  }

  // 4방향으로 밀어보기
  vector<vector<int>> tmp = board;
  for (int i=0; i<4; i++) {
    switch (i) {
    case 0:
      northWind();
      dfs(depth+1);
      board = tmp;
      break;
    case 1:
      westWind();
      dfs(depth+1);
      board = tmp;
      break;
    case 2:
      southWind();
      dfs(depth+1);
      board = tmp;
      break;
    case 3:
      eastWind();
      dfs(depth+1);
      board = tmp;
      break;
    }
  }
}

int solution() {
  dfs(0);

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  int test;
  cin >> test;

  for (int t=1; t<=test; t++) {
    cin >> n >> m >> k;

    ans = 0;
    for (int i=0; i<n; i++)
      for (int j=0; j<m; j++) {
        cin >> board[i][j];
      }

    cout << "#" << t << " " << solution() << endl;
  }
}