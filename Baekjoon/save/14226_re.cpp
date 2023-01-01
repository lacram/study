#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
int dp[1001][1001];

int solve(int board, int cb){
  if (board == n) return 0;
  if (board > 1000) return 10000;

  int & ret = dp[board][cb];
  if (ret != -1) return ret;
  ret = 10000;

  // 복사
  if (cb != board) ret = min(ret, solve(board, board)+1);
  // 붙여넣기
  if (cb) ret = min(ret, solve(board+cb, cb)+1);
  // -1
  if (board > 1) ret = min(ret, solve(board-1, cb)+1);

  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  memset(dp, -1, sizeof(dp));

  cout << solve(1,0);
}