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

int n,t;
int m;
long long dp[31][31];

/* 
dp[i][j] = dp[i-1][i-1]~dp[i-1][j-1] 합
 */

long long solution() {
  for (int i=1; i<31; i++) {
    dp[1][i] = i;
  }

  for (int i=2; i<=n; i++)
    for (int j=2; j<=m; j++) {
      for (int k=i-1; k<=j-1; k++) {
        dp[i][j] += dp[i-1][k];
      }
    }

  return dp[n][m];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> t;

  for (int i=0; i<t; i++){
    cin >> n >> m;
    cout << solution() << endl;
  }

}