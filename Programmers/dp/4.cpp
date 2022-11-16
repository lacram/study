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

int board[101][101];
int pud[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {

  for (int i=1; i<=m; i++) {
    board[i][1] = 1;
  }
  for (int i=1; i<=n; i++) {
    board[1][i] = 1;
  }

  for (auto puddle : puddles) {
    int x = puddle[0];
    int y = puddle[1];

    if (x == 1) {
      for (int i=y; i<=n; i++) {
        board[1][i] = 0;
      }
    }
    if (y == 1) {
      for (int i=x; i<=m; i++) {
        board[i][1] = 0;
      }
    }
  }

  for (auto puddle : puddles) {
    int x = puddle[0];
    int y = puddle[1];

    pud[x][y] = 1;
  }

  for (int i=2; i<=m; i++)
    for (int j=2; j<=n; j++) {
      if (!pud[i][j]) board[i][j] = (board[i-1][j] + board[i][j-1]) % 1000000007;
    }
  
  return board[m][n] % 1000000007;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution(4,3,{{2,1},{3,1}});

}