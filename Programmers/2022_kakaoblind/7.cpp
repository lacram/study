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

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int w,h;

// 승리여부, 이동횟수
pair<int,int> sol(bool turn, pair<int,int> p1, pair<int,int> p2, int cnt, vector<vector<int>> board) {
  
  if (turn) board[p1.first][p1.second] = 0;
  else board[p2.first][p2.second] = 0;

  vector<pair<int,int>> v;

  for (int i=0; i<4; i++) {
    int nx,ny;
    if (turn) {
      nx = p1.first + dx[i];
      ny = p1.second + dy[i];
    } else {
      nx = p2.first + dx[i];
      ny = p2.second + dy[i];
    }

    if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
    if (board[nx][ny] == 0) continue;
    // 같은 칸에 있을 경우 이동 가능하면
    if ((p1.first == p2.first) && (p1.second == p2.second)) {
      return {1,cnt+1};
    }

    if (turn) v.push_back(sol(!turn, {nx,ny}, p2, cnt+1, board));
    else v.push_back(sol(!turn, p1, {nx,ny}, cnt+1, board));
  }

  if (turn) board[p1.first][p1.second] = 1;
  else board[p2.first][p2.second] = 1;

  int minWinCost = cnt;
  int maxLoseCost = cnt;
  bool flag = false;
  for (auto a : v) {
    bool win = a.first;
    int cost = a.second;

    if (win) {
      flag = true;
      minWinCost = min(minWinCost, cost);
    }
    else maxLoseCost = max(maxLoseCost, cost);
  }  

  if (flag) return {1,minWinCost};
  else return {0,maxLoseCost};
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
  h = board.size();
  w = board[0].size();
  pair<int,int> p1 = {aloc[0], aloc[1]};
  pair<int,int> p2 = {bloc[0], bloc[1]};
  board[aloc[0]][aloc[1]] = 0;
  board[bloc[0]][bloc[1]] = 0;
  
  return sol(1,p1,p2,0,board).second;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}, {1, 0}, {1, 2});

}