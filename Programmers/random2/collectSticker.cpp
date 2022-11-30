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

/* 
dp
첫번째 스티커를 떼었을 경우 - 마지막 스티커는 못 뗌 0~n-1
dp[0] = s[0]
dp[1] = dp[0]

첫번째 스티커를 안 떼었을 경우 - 마지막 스티커도 뗄 수 있음 
dp[0] = 0
dp[1] = s[1]

dp[n] = dp[n-2] + s[n], dp[n-1]
 */

int dp[100000];
int dp2[100000];

int solution(vector<int> sticker) {
  int n = sticker.size();
  if (n == 1) return sticker[0];

  // 첫번째 스티커를 뗌
  dp[0] = sticker[0];
  dp[1] = dp[0];
  for (int i=2; i<n-1; i++) {
    dp[i] = max(dp[i-2] + sticker[i], dp[i-1]);
  }

  // 첫번째 스티커를 안 뗌
  dp2[0] = 0;
  dp2[1] = sticker[1];
  for (int i=2; i<n; i++) {
    dp2[i] = max(dp2[i-2] + sticker[i], dp2[i-1]);
  }

  return max(dp[n-2], dp2[n-1]);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution({3});

}