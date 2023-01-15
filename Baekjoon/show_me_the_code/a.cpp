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
int arr[100001];
vector<vector<int>> dp(100001, vector<int>(2));

int solution() {
  int ans = 0;
  for (int i=1; i<=n; i++) {
    // 왼
    if (arr[i] == 1) {
      dp[i][0] = max(1, dp[i-1][0]+1);
      dp[i][1] = dp[i-1][1] - 1;
    }
    // 오
    else {
      dp[i][0] = dp[i-1][0] - 1;
      dp[i][1] = max(1, dp[i-1][1]+1);
    }

    ans = max({ans ,dp[i][0], dp[i][1]});
  }

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;

  // cin.open("input.txt");
  cin >> n;

  for (int i=1; i<=n; i++){
    cin >> arr[i];
  }

  cout << solution();
}