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

int n,m,k;
int score;
int board[20][20];

/* 
1. 이동방향으로 한칸 이동
2. 점수 획득
3. 이동방향 결정

 */

// dir 우 하 좌 상
struct Dice{
  int top;
  int bottom;
  int right;
  int left;
  int up;
  int down;

  pair<int,int> pos;  
  int dir;
}dice;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int visited[20][20];
int calcScore[20][20];
vector<pair<int,int>> v;

void ifCantMove() {
  if ((dice.dir == 0 && dice.pos.second == m-1) || 
      (dice.dir == 2 && dice.pos.second == 0)   || 
      (dice.dir == 1 && dice.pos.first == n-1)  || 
      (dice.dir == 3 && dice.pos.first == 0) 
  ) {
    dice.dir = (dice.dir + 2) % 4;
  }

}

void move() {
  ifCantMove();

  if (dice.dir == 0) {
    dice.right = dice.top;
    dice.top = dice.left;
    dice.left = dice.bottom;
    dice.pos = {dice.pos.first, dice.pos.second+1};
  } else if (dice.dir == 1) {
    dice.down = dice.top;
    dice.top = dice.up;
    dice.up = dice.bottom;
    dice.pos = {dice.pos.first+1, dice.pos.second};
  } else if (dice.dir == 2) {
    dice.left = dice.top;
    dice.top = dice.right;
    dice.right = dice.bottom;
    dice.pos = {dice.pos.first, dice.pos.second-1};
  } else if (dice.dir == 3) {
    dice.up = dice.top;
    dice.top = dice.down;
    dice.down = dice.bottom;
    dice.pos = {dice.pos.first-1, dice.pos.second};
  }
  dice.bottom = 7 - dice.top;
}

int getScore(int x, int y, int num) {
  
  int& ret = calcScore[x][y];
  if (ret != 0) return ret;

  ret = num;
  visited[x][y] = 1;

  for (int i=0; i<4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
    if (visited[nx][ny]) continue;
    if (board[nx][ny] != num) continue;
    
    v.push_back({nx,ny});
    ret += getScore(nx,ny,num);
  }

  return ret;
}

void addScore() {
  memset(visited, 0, sizeof(visited));
  v.clear();

  int myScore = getScore(dice.pos.first, dice.pos.second, board[dice.pos.first][dice.pos.second]);
  for (auto a : v) {
    calcScore[a.first][a.second] = myScore;
  }

  score += myScore;
}

void decideDir() {
  int a = dice.bottom;
  int b = board[dice.pos.first][dice.pos.second];

  if (a > b) dice.dir = (dice.dir + 1) % 4;
  if (a < b) dice.dir = (dice.dir - 1 + 4) % 4;
}

int solution() {
  dice.top = 1;
  dice.bottom = 6;
  dice.right = 3;
  dice.left = 4;
  dice.up = 2;
  dice.down = 5;

  while (k--) {
    move();
    addScore();
    decideDir();
  }
  return score;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m >> k;

  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++) {
      cin >> board[i][j];      
    }
  }

  cout << solution();
}