#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#define endl '\n'
#define INF 2000000000

using namespace std;

int n,k;
int dp[201][201];

/* 
dp[i][j] = sum(dp[0~i][j-1])
 */

int solution() {
  for (int i=0; i<=k; i++)
    dp[0][i] = 1;

  for (int i=1; i<=n; i++)
    for (int j=1; j<=k; j++) {
      for (int k=0; k<=i; k++) {
        dp[i][j] += dp[k][j-1];
        dp[i][j] %= 1000000000;
      }
    }
  
  return dp[n][k];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> k;

  cout << solution();
}