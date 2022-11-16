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

// 우 하 좌 상
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<vector<int>> rectangles;
int visited[51][51];

bool onSquare(double x, double y, vector<int> rectangle) {
  int x1 = rectangle[0];
  int y1 = rectangle[1];
  int x2 = rectangle[2];
  int y2 = rectangle[3];

  if (x1 <= x && x <= x2) {
    if (y == y1 || y == y2) return true;
  }
  if (y1 <= y && y <= y2) {
    if (x == x1 || x == x2) return true;
  }
  return false;
}

bool inSquare(double x, double y) {
  for (auto rectangle : rectangles) {
    int x1 = rectangle[0];
    int y1 = rectangle[1];
    int x2 = rectangle[2];
    int y2 = rectangle[3];

    if (x1 < x && x < x2 && y1 < y && y < y2) return true;
  }
  return false;
}

bool canMove(double x, double y) {
  for (auto rectangle : rectangles) {
    if (onSquare(x,y,rectangle) && !inSquare(x,y)) return true;
  }
  return false;
}

int bfs(int characterX, int characterY, int itemX, int itemY) {
  // 횟수,x,y
  queue<vector<int>> q;
  
  q.push({0,characterX,characterY});

  while(!q.empty()) {
    int cnt = q.front()[0];
    int x = q.front()[1];
    int y = q.front()[2];

    if (x == itemX && y == itemY) return cnt;

    q.pop();

    for (int i=0; i<4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      // 출발점과 도착점의 중간이 라인 위에 위치해야함
      if (!canMove(nx-dx[i]*0.5,ny-dy[i]*0.5)) continue;
      if (visited[nx][ny]) continue;
      
      visited[nx][ny] = 1;
      q.push({cnt+1,nx,ny});
    }
  }
}

int solution(vector<vector<int>> r, int characterX, int characterY, int itemX, int itemY) {
  rectangles = r;

  return bfs(characterX,characterY,itemX,itemY);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution({{1,1,7,4},{3,2,5,5},{4,3,6,9},{2,6,8,8}},1,	3,	7,	8);

}