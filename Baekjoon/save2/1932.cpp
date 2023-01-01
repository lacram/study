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
vector<vector<int>> board(500, vector<int>(500));

int solution() {
  for (int i=1; i<n; i++)
    for (int j=0; j<n; j++) {
      if (j == 0) board[i][j] += board[i-1][j];
      else if (j == n-1) board[i][j] += board[i-1][j-1];
      else {
        board[i][j] += max(board[i-1][j-1], board[i-1][j]);
      }
    }

  return *max_element(board[n-1].begin(), board[n-1].end());
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    for (int j=0; j<=i; j++) {
      cin >> board[i][j];
    }
  }

  cout << solution();
}