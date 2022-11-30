#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <cmath>

using namespace std;

int matrix[501][2];
int d[501];
int dp[501][501];

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  // ifstream cin;
  // cin.open("test.txt");

  int n;
  cin >> n;

  for (int i=0; i<n; i++){
    cin >> matrix[i][0] >> matrix[i][1];
    d[i] = matrix[i][0];
  }
  d[n] = matrix[n-1][1];

  
  for (int i=0; i<=n; i++)
    for (int j=0; j<=n; j++){
      if (i==j) dp[i][i] = 0;
      else dp[i][j] = pow(2,31)-1;
    }

  for (int t=1; t<n; t++)
    for (int i=1; i<=n-t; i++){
      int j=i+t;
      for (int k=i; k<j; k++){
        dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+d[i-1]*d[k]*d[j]);
      }
    }

  cout << dp[1][n];
  
}