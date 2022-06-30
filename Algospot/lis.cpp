#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

int arr[500];
int dp[500];

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  // ifstream cin;
  // cin.open("test.txt");

  int test, n;
  cin >> test;

  while (test--){
    cin >> n;

    for (int i=0; i<n; i++)
      cin >> arr[i];

    memset(dp, 0 ,sizeof(dp));
    dp[0] = 1;
    int ret=1;
    for (int i=1; i<n; i++){
      // dp[i] = arr[i] 보다 작은arr[j] 중 dp[j]가 max
      // 1 3 6 4 5 8 6 4
      // 1 2 3 3 4 5 4 3
      int M=0;
      for (int j=0; j<=i; j++){
        if (arr[j] < arr[i])
          M = max(M, dp[j]);
      }
      dp[i] = M+1;
      ret = max(dp[i], ret);
    }

    cout << ret << endl;
  }
  
}