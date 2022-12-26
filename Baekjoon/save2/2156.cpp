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
int arr[10000];
vector<vector<int>> dp(10000, vector<int>(3));

/* 
연속으로 놓여 있는 3잔을 모두 마실 수는 없다.
 */

int solution() {
  dp[0][1] = arr[0];
  dp[1][1] = arr[1];
  dp[1][2] = arr[0] + arr[1];

  for (int i=2; i<n; i++) {
    dp[i][0] = *max_element(dp[i-1].begin(), dp[i-1].end());
    dp[i][1] = *max_element(dp[i-2].begin(), dp[i-2].end()) + arr[i];
    dp[i][2] = dp[i-1][1] + arr[i];
  }
  return *max_element(dp[n-1].begin(), dp[n-1].end());
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    cin >> arr[i];
  }

  cout << solution();
}