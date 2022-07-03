#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int test, n;
int dp[100][100];
int board[100][100];

// x,y에서 마지막 줄까지 갈때 최대값
int solve(int x, int y){
  if (x==n-1) return board[x][y];

  int& ret = dp[x][y];
  if (ret != -1) return ret;

  return ret = max(solve(x+1,y), solve(x+1,y+1))+board[x][y];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> test;
  while(test--){
    cin >> n;

    for (int i=0; i<n; i++)
      for (int j=0; j<=i; j++)
        cin >> board[i][j];
    
    memset(dp,-1,sizeof(dp));

    cout << solve(0,0) << endl;
  }
}