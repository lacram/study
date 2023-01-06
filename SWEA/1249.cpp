#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
// #include<fstream>
#include <queue>

using namespace std;

int n,m;
int board[100][100];
int dist[100][100];
string tmp[100];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

/* 
다익스트라
 */

void bfs() {
  // 비용, x,y
  queue<vector<int>> q;
  q.push({0,0});
  dist[0][0] = 0;

  while (!q.empty()) {
    int x = q.front()[0];
    int y = q.front()[1];
    q.pop();

    for (int i=0; i<4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

      if (dist[nx][ny] <= dist[x][y] + board[nx][ny]) continue;

      dist[nx][ny] = dist[x][y] + board[nx][ny];
      q.push({nx,ny});
    }
  }
}

int solution() {
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      dist[i][j] = 99999999;
    }
  }

  bfs();

  return dist[n-1][n-1];
}

int main()
{
	// ifstream cin;
	// cin.open("input.txt");

  int test;
  cin >> test;
	for (int k = 1; k <= test; k++) {
    cin >> n;

    for (int i=0; i<n; i++) {
      string str;
      cin >> str;
      for (int j=0; j<n; j++) {
        board[i][j] = str[j] - '0';
      }
    }
		cout << "#" << k << " " << solution() << endl;
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

