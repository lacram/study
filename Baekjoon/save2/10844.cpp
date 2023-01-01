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
10 89
210 789 989
1010 1210 3210 8989 8789 6789

1 : 9,  1 8 (1~9)
2 : 17, 2 15 
3 : 32, 

 */

int dp[101][10];

int solution() {
  for (int i=1; i<=9; i++) {
    dp[1][i] = 1;
  }

  for (int i=2; i<=n; i++) {
    for (int j=0; j<=9; j++) {
      if (j == 0) {
        dp[i][1] += dp[i-1][0];
        dp[i][1] %= 1000000000;
      }
      else if (j == 9) {
        dp[i][8] += dp[i-1][9];
        dp[i][8] %= 1000000000;
      }
      else {
        dp[i][j-1] += dp[i-1][j];
        dp[i][j-1] %= 1000000000;
        dp[i][j+1] += dp[i-1][j];
        dp[i][j+1] %= 1000000000;
      }
    }
  } 

  int ans = 0;
  for (int i=0; i<=9; i++) {
    ans += dp[n][i];
    ans %= 1000000000;
  }

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;10
  // cin.open("input.txt");

  cin >> n;

  cout << solution();
}