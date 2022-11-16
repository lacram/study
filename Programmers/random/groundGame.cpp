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

int dp[100000][4];

/* 
dp[n+1][k] = max(dp[n][not(k)]) + land[n+1][k]
 */

int solution(vector<vector<int>> land) {
  int n = land.size();
  for (int i=0; i<4; i++) {
    dp[0][i] = land[0][i];
  }

  for (int i=1; i<n; i++) {
    for (int j=0; j<4; j++) {
      for (int k=0; k<4; k++){
        if (j != k) {
          dp[i][j] = max(dp[i][j], dp[i-1][k] + land[i][j]);
        }
      }
    }
  }

  int res = 0;
  for (int i=0; i<4; i++) {
    res = max(res, dp[n-1][i]);
  }
  return res;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution({{1,2,3,5},{5,6,7,8},{4,3,2,1}});

}