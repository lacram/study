#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#define endl '\n'
#define INF 2000000000

using namespace std;

/* 
dp[1][1] = dp[0][0]+money[1]
dp[1][0] = max(dp[0][0], dp[0][1]

 */

int dp[1000001][2];
int dp2[1000001][2];

int solution(vector<int> money) {
  int n = money.size();

  // 첫번쨰 집을 턴 경우
  dp[0][1] = money[0];
  dp[1][1] = 0;
  dp[1][0] = money[0];
  for (int i=2; i<n-1; i++) {
    dp[i][1] = dp[i-1][0] + money[i];
    dp[i][0] = max(dp[i-1][0] , dp[i-1][1]);
  }

  // 안 턴 경우
  for (int i=1; i<n; i++) {
    dp2[i][1] = dp2[i-1][0] + money[i];
    dp2[i][0] = max(dp2[i-1][0] , dp2[i-1][1]);
  }

  return max(max(dp[n-2][0], dp[n-2][1]), max(dp2[n-1][0], dp2[n-1][1]));
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}