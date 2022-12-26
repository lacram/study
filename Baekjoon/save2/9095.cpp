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

/* 
dp[n] = dp[n-3] + dp[n-2] + dp[n-1]
 */

int dp[11];

int solution() {
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  for (int i=4; i<=n; i++) {
    dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
  }
  return dp[n];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  int t;
  cin >> t;

  for (int i=0; i<t; i++) {
    cin >> n;
    cout << solution() << endl;
  }
}