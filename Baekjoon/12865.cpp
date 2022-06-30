#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, w;

  cin >> n >> w;

  int stuff[n+1][2];  
  
  for (int i=1; i<n+1; i++){
    cin >> stuff[i][0] >> stuff[i][1];
  }

  int dp[n+1][w+1];
  memset(dp, 0, sizeof(dp));

  for (int i=1; i<n+1; i++)
    for (int j=1; j<w+1; j++){
      if (j-stuff[i][0] >= 0)
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-stuff[i][0]] + stuff[i][1]);
      else dp[i][j] = dp[i-1][j];
      } 
      
  cout << dp[n][w];
}