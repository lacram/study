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

/* 
dp[i][j] i~j 행렬 곱셉 연산의 최소
dp[i][j] = dp[i][k] + dp[k][j] + matrix_sizes[i][0] * matrix_sizes[k][1] * matrix_sizes[j][1]
dp[i][i] = 0
 */

int dp[200][200];

int solution(vector<vector<int>> matrix_sizes) {
  int n = matrix_sizes.size();
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) {
      if (i != j) dp[i][j] = INF;
    }

  // 크기
  for (int t=1; t<n; t++)
    for (int i=0; i+t<n; i++) {
      int j = i+t;
      for (int k=i; k<j; k++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + matrix_sizes[i][0] * matrix_sizes[k][1] * matrix_sizes[j][1]);
      }
    }
  
  return dp[0][n-1];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}