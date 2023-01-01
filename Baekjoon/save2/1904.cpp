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
1 : 1
2 : 2
3 : 3
4 : 5
 */

int dp[1000001];

int solution() {
  dp[1] = 1;
  dp[2] = 2;
  for (int i=3; i<=n; i++) {
    dp[i] = (dp[i-2] + dp[i-1]) % 15746;
  }
  return dp[n];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  cout << solution();
}