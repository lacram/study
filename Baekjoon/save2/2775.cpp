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

int n;

int dp[15][15];

/* 
dp[i][j] = sum(dp[i-1][0~j])
 */

int solution(int k, int m) {
  for (int i=0; i<=14; i++) {
    dp[0][i] = i;
  }

  for (int i=1; i<=14; i++)
    for (int j=1; j<=14; j++) {
      int res = 0;
      for (int t=1; t<=j; t++){
        res += dp[i-1][t];
      }
      dp[i][j] = res;
    }
  return dp[k][m];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    int k,m;
    cin >> k >> m;
    cout << solution(k,m) << endl; 
  }
}