#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int h,w;
int board[1000];
int dp[1000];
int dir[2][1000];

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> h >> w;

  for (int i=0; i<h; i++){
    for (int j=0; j<w; j++){
      cin >> board[j];
    }
    
    // 첫줄 
    if (i==0){
      dp[0] = board[0];
      for (int j=1; j<w; j++)
        dp[j] += dp[j-1]+board[j];
    }

    // 둘째줄
    else {
      dir[0][0] = dp[0] + board[0];
      dir[1][w-1] = dp[w-1] + board[w-1];

      for (int j=1; j<w; j++){
        dir[0][j] = max(dp[j], dir[0][j-1]) + board[j];
        dir[1][w-1-j] = max(dp[w-1-j], dir[1][w-j]) + board[w-1-j];
      }

      for (int j=0; j<w; j++)
        dp[j] = max(dir[0][j], dir[1][j]);
    }
  }

  cout << dp[w-1];
}