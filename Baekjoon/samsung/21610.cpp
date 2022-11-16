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

int n,m;

int board[50][50];
vector<pair<int,int>> moves;
// 1~8
int dx[9] = {0,0,-1,-1,-1,0,1,1,1};
int dy[9] = {0,-1,-1,0,1,1,1,0,-1};

// diagonal
int ddx[4] = {-1,-1,1,1};
int ddy[4] = {-1,1,1,-1};

vector<pair<int,int>> clouds;

/* 
1. 비바라기 시전시 (N, 1), (N, 2), (N-1, 1), (N-1, 2)에 비구름이 생긴다
2. 모든 행, 열은 이어져있다.
3. ←, ↖, ↑, ↗, →, ↘, ↓, ↙
   1,  2, 3, 4,  5, 6, 7,  8

1. 모든 구름이 di 방향으로 si칸 이동한다.
2. 각 구름에서 비가 내려 구름이 있는 칸의 바구니에 저장된 물의 양이 1 증가한다.
3. 구름이 모두 사라진다.
4. 2에서 물이 증가한 칸 (r, c)에 물복사버그 마법을 시전한다. 물복사버그 마법을 사용하면, 대각선 방향으로 거리가 1인 칸에  물이 있는 바구니의 수만큼 (r, c)에 있는 바구니의 물이 양이 증가한다.
이때는 이동과 다르게 경계를 넘어가는 칸은 대각선 방향으로 거리가 1인 칸이 아니다.
예를 들어, (N, 2)에서 인접한 대각선 칸은 (N-1, 1), (N-1, 3)이고, (N, N)에서 인접한 대각선 칸은 (N-1, N-1)뿐이다.
5.바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생기고, 물의 양이 2 줄어든다. 이때 구름이 생기는 칸은 3에서 구름이 사라진 칸이 아니어야 한다

*/

void moveClouds(int idx) {
  int dir = moves[idx].first;
  int len = moves[idx].second;

  for (int i=0; i<clouds.size(); i++) {
    int x = clouds[i].first;
    int y = clouds[i].second;

    // 행, 열이 연결되어있으므로
    int nx = (x + dx[dir]*len + n*30)%n;
    int ny = (y + dy[dir]*len + n*30)%n;

    clouds[i].first = nx;
    clouds[i].second = ny;
  }
}

void rain() {
  for (auto cloud : clouds) {
    int x = cloud.first;
    int y = cloud.second;

    board[x][y]++;
  }
}

void magic() {
  for (auto cloud : clouds) {
    int x = cloud.first;
    int y = cloud.second;
    int cnt = 0;

    for (int i=0; i<4; i++) {
      int nx = x + ddx[i];
      int ny = y + ddy[i];

      if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

      if (board[nx][ny]) cnt++;
    }

    board[x][y] += cnt;
  }
}

void makeClouds() {
  vector<pair<int,int>> newClouds = {};

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) {
      if (board[i][j] >= 2) {
        // 기존에 구름이었으면 안됨
        bool flag = false;
        for (auto cloud : clouds) {
          if (i == cloud.first && j == cloud.second) {
            flag = true;
            break;
          }
        }
        if (flag) continue;

        board[i][j] -= 2;
        newClouds.push_back({i,j});
      }
    }
  
  clouds = newClouds;
}

int getAns() {
  int ans = 0;
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      ans += board[i][j];
  
  return ans;
}

void print() {
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++)
      cout << board[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}

int solution() {
  int t = m;
  while (t--) {
    moveClouds(m-t-1);
    rain();
    magic();
    makeClouds();
  }
  return getAns();
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++) 
      cin >> board[i][j];
  }

  for (int i=0; i<m; i++) {
    int d,s;  
    cin >> d >> s;
    moves.push_back({d,s});
  }

  clouds = {{n-1,0},{n-1,1},{n-2,0},{n-2,1}};

  cout << solution();
}