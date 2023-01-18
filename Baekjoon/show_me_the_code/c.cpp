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

int n,m,c;
long long dp[1001][1001];
long long dp2[1001][1001];
int a[1001];
int b[1001];
int w[1001][1001];

/* 
이중 dp
dp[i][j] = dp[i][j-1], max(w[i][j] + dp[i-1][j-1] ~ w[1][j] + dp[0][j-1])
 */

long long solution() {
  memset(dp2, -1, sizeof(dp2));

  for (int i=1; i<=n; i++) 
    for (int j=1; j<=m; j++) {
      long long tmp = 0;
      for (int k=1; k<=i; k++) {
        long long& res = dp2[k][j];
        if (res != -1) tmp = max(tmp, res);
        else {
          res = w[a[k]][b[j]] + dp[k-1][j-1];
          tmp = max(tmp, res);
        }
      }
      dp[i][j] = max(dp[i][j-1], tmp);
    }
    
  return dp[n][m];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m >> c;

  for (int i=1; i<=c; i++){
    for (int j=1; j<=c; j++)
      cin >> w[i][j];
  }

  for (int i=1; i<=n; i++) {
    cin >> a[i];
  }

  for (int i=1; i<=m; i++) {
    cin >> b[i];
  }

  cout << solution();
}