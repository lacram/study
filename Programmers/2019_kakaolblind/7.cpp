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

vector<vector<int>> board;
int ans = 0;

vector<vector<vector<int>>> can = {
  {{0,1,1,1}, {0,0,1,2}},
  {{0,1,2,2}, {0,0,0,-1}},
  {{0,1,2,2}, {0,0,0,1}},
  {{0,1,1,1}, {0,0,-1,-2}},
  {{0,1,1,1}, {0,-1,0,1}}
};

vector<vector<vector<int>>> need = {
  {{0,0},{1,2}},
  {{0,1},{-1,-1}},
  {{0,1},{1,1}},
  {{0,0},{-1,-2}},
  {{0,0},{-1,1}}
};

bool check(int x1, int y1, int x2, int y2){
  for (int i=x1; i>=0; i--){
    if (board[i][y1]) return false;
  }
  for (int i=x2; i>=0; i--){
    if (board[i][y2]) return false;
  }
  return true;
}

bool canDelete(int x, int y){
  int num = board[x][y];

  for (int j=0; j<can.size(); j++) {
    bool flag = true;
    for (int i=0; i<4; i++){
      int dx = x + can[j][0][i];
      int dy = y + can[j][1][i];

      if (dx < 0 || dy < 0 || dx >= board.size() || dy >= board.size()) {
        flag = false;
        break;
      }

      if (board[dx][dy] != num) flag = false;
    }

    // 가능한 케이스이고
    if (flag) {
      // 블럭을 채울 수 있으면
      if (check(x+need[j][0][0],y+need[j][1][0],x+need[j][0][1],y+need[j][1][1])) {
        for (int i=0; i<4; i++){
          int dx = x + can[j][0][i];
          int dy = y + can[j][1][i];
          
          board[dx][dy] = 0;
        }
        ans++;
        return true;
      }
    }
  }
  return false;
}

int solution(vector<vector<int>> b) {
  board = b;

  while(1) {
    bool flag = false;
    for (int i=0; i<board.size(); i++)
      for (int j=0; j<board.size(); j++){
        if (board[i][j]) {
          if (canDelete(i,j))
            flag = true;
        }
      }
    if (!flag) break;
  }
  
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution({{0,0,0,0,0,0,0,0,0,0}
,{0,0,0,0,0,0,0,0,0,0}
,{0,0,0,0,0,0,0,0,0,0}
,{0,0,0,0,0,0,0,0,0,0}
,{0,0,0,2,2,0,0,0,0,0}
,{0,0,0,2,1,0,0,0,0,0}
,{0,0,0,2,1,0,0,0,0,0}
,{0,0,0,0,1,1,0,0,0,0}
,{0,0,0,0,0,0,0,0,0,0}
,{0,0,0,0,0,0,0,0,0,0}});

}