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

int n;
int m;
int k;
int ans = INF;
vector<int> destination;

void flipCol(vector<vector<int>>& beginning, int line) {
  for (int i=0; i<m; i++) {
    beginning[line][i] = !beginning[line][i];
  }
}

void flipRow(vector<vector<int>>& beginning, int line) {
  for (int i=0; i<n; i++) {
    beginning[i][line] = !beginning[i][line];
  }
}

bool check(vector<vector<int>> beginning, vector<vector<int>> target) {
  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++) {
      if (beginning[i][j] != target[i][j]) {
        return false;
      }
    }
  return true;
}

/* 
열에 대한 모든 경우의 수 1024에 대해
행을 뒤집어가며 최소의 경우를 찾느다
 */

int LineToNum(vector<int> line) {
  int ans = 0;
  for (int i=0; i<m; i++) {
    ans += line[i] << i;
  }
  return ans;
}

int makeGoal(vector<vector<int>> board) {
  vector<int> numLines;
  for (auto line : board) {
    numLines.push_back(LineToNum(line));
  }

  int cnt = 0;
  for (int i=0; i<n; i++) {
    int my = numLines[i];
    int goal = destination[i];

    // 숫자를 111111과 xor 연산하면 비트가 뒤집어짐
    if (my == goal) continue;
    else if ((my^((1<<m)-1)) == goal) cnt++;
    else return INF;
  }
  return cnt;
}

void dfs(vector<vector<int>> board, int cnt, int depth) {
  if (depth == m) {
    k++;
    ans = min(ans, makeGoal(board)+cnt);
    return;
  }

  dfs(board,cnt,depth+1);
  flipRow(board,depth);
  dfs(board,cnt+1,depth+1);
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
  n = beginning.size();
  m = beginning[0].size();

  for (auto line : target) {
    destination.push_back(LineToNum(line));
  }

  dfs(beginning, 0, 0);
  cout << k <<endl;

  return ans == INF ? -1 : ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}    ,   {{1, 0, 1}, {0, 0, 0}, {0, 0, 0}} );

}