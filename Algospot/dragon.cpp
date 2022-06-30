#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

string str = "FX+YF";
long long dp[51];

char solve(int srt, int n){
  if (srt < 5)
    return str[srt];

  if (srt == dp[n]/4 or srt == dp[n]/2)
    return '+';
  if (srt == dp[n]-1-dp[n]/4)
    return '-';
  
  if (srt < dp[n]/2)
    return solve(srt, n-1);

  if (dp[n]/2 < srt <=dp[n])
    return solve(srt-dp[n]/2-1, n-1);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  // ifstream cin;
  // cin.open("test.txt");

  int test, n, p, l;
  cin >> test;

  while (test--){
    cin >> n >> p>> l;

    dp[0] = 2;
    for (int i=1; i<=n; i++)
      dp[i] = dp[i-1]*2 +1;

    for (int i=p; i<p+l; i++)
      cout << solve(i-1,n);
    cout << endl;
  }
  
}