#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

int score[101];
int times[101];
int dp[101][10001];
int n;
int total;


int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  // ifstream cin;
  // cin.open("test.txt");

  cin >> n >> total;

  for (int i=1; i<=n; i++){
    cin >> times[i] >> score[i];
  }
  
  for (int i=0; i<=n; i++)
    for (int j=0; j<=total; j++){
      if (i==0 || j==0) dp[i][j] = 0;
      else {
        if (j-times[i] >= 0) dp[i][j] = max(dp[i-1][j], dp[i-1][j-times[i]]+score[i]);
        else dp[i][j] = dp[i-1][j];
      }
    }

  cout << dp[n][total];
    
}