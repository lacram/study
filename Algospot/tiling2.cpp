#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

int dp[101];

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  // ifstream cin;
  // cin.open("test.txt");

  int test,n;
  cin >> test;

  while (test--){
    cin >> n;
    
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; i++)
      dp[i] = (dp[i-2]+dp[i-1])%1000000007;

    cout << dp[n] << endl;
  }
  
}