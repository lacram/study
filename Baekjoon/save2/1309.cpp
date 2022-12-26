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
// 0 - 계산값, 1 - 누적값
int dp[100001][2];

int solution() {
  dp[1][0] = 2;
  dp[1][1] = 2;
  for (int i=2; i<=n; i++) {
    dp[i][0] = (dp[i-2][1]*2 + dp[i-1][0] + 2) % 9901;
    dp[i][1] += dp[i-1][1] + dp[i][0];
    dp[i][1] %= 9901;
  }

  return (dp[n][1]+1)%9901;
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