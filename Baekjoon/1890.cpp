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
int board[101][101];
long long dp[101][101];

long long solution() {
  dp[1][1] = 1;
  for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++) {
      if (i == n && j == n) break;

      int num = board[i][j];
      if (i+num <=n) dp[i+num][j] += dp[i][j];
      if (j+num <=n) dp[i][j+num] += dp[i][j];
    }

  return dp[n][n];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=1; i<=n; i++){
    for (int j=1; j<=n; j++)
      cin >> board[i][j];
  }

  cout << solution();
}