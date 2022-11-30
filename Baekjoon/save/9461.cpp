#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int test, n;
  cin >> test;

  while (test--){
    cin >> n;

    long long dp[101]={0,1,1,1,2,2,};
    dp[4] = 2;
    dp[5] = 2;
    for (int i=6; i<=n; i++){
      dp[i] = dp[i-5] + dp[i-1];
    }

    cout << dp[n] << endl;
  }
  
}