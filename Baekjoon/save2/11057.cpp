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

int dp[1001][10];

/* 
0으로 끝나는 숫자 = [i-1] 0으로 끝나는 숫자
1로 끝나는 숫자 = [i-1] 0으로 끝나는 숫자 + [i-1] 1로 끝나는 숫자
2로 끝나는 숫자 = [i-1] 0으로 끝나는 숫자 + [i-1] 1로 끝나는 숫자 + [i-1] 2로 끝나는 숫자
dp[i][j] = dp[i][j-1] + dp[i-1][j]

 */

int solution() {
  for (int i=0; i<10; i++) {
    dp[1][i] = 1; 
  }
  for (int i=2; i<=n; i++) {
    for (int j=0; j<10; j++) {
      if (j == 0) dp[i][j] = dp[i-1][j];
      else dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % 10007;
    }
  }

  int ans = 0;
  for (int i=0; i<10; i++) {
    ans += dp[n][i];
  }

  return ans % 10007;
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