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
int board[5][5];
int maxNum = -INF;
int minNum = INF;

int dx[2] = {0,1};
int dy[2] = {1,0};

void bfs() {
  // {x,y,num,op};
  queue<vector<int>> q;
  q.push({0,0,board[0][0],0});

  while (!q.empty()) {
    int x = q.front()[0];
    int y = q.front()[1];
    int num = q.front()[2];
    char op = (char)q.front()[3];
    q.pop();

    if (x == n-1 && y == n-1) {
      maxNum = max(maxNum, num);
      minNum = min(minNum, num);
      continue;
    }

    for (int i=0; i<2; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
    
      if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

      if (0 <= board[nx][ny] && board[nx][ny] <= 9) {
        if (op == '+') q.push({nx,ny,num+board[nx][ny],0});
        else if (op == '-') q.push({nx,ny,num-board[nx][ny],0});
        else if (op == '*') q.push({nx,ny,num*board[nx][ny],0});
      }
      else q.push({nx,ny,num,board[nx][ny]});
    }
  }
}

void solution() {
  bfs();

  cout << maxNum << " " << minNum;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++) {
      char a;
      cin >> a;
      if ('0' <= a && a <= '9') a -= '0';
      board[i][j] = a;
    }
  }

  solution();
}