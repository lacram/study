#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int test, n;
int board[100][100];
int dp[100][100];

int solve(int x, int y){
  if (x == n-1 && y == n-1) return 1;

  int& ret = dp[x][y];
  if (ret != -1) return ret;
  ret = 0;

  if (x+board[x][y] < n) ret = solve(x+board[x][y],y);
  if (y+board[x][y] < n) ret = ret || solve(x,y+board[x][y]);

  return ret;
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
      for (int j=0; j<n; j++)
        cin >> board[i][j];
    
    memset(dp, -1, sizeof(dp));

    if (solve(0,0)) cout << "YES" << endl;
    else cout << "NO" << endl;
    

  }
}