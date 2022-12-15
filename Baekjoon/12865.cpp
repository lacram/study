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

int n,k;

/* 
dp[i][j] : i번째 물품 차례일때 j무게일 경우 최대 가치

 */

int arr[101][2];
vector<vector<int>> dp(101, vector<int>(100001));

int solution() {

  for (int i=1; i<=n; i++){
    int weight = arr[i][0];
    int value = arr[i][1];
    for (int j=1; j<=k; j++) {
      if (j-weight >= 0) dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight] + value);
      else dp[i][j] = dp[i-1][j];
    }
  }
  return *max_element(dp[n].begin(), dp[n].end());
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> k;

  for (int i=1; i<=n; i++){
    for (int j=0; j<2; j++)
      cin >> arr[i][j];
  }

  cout << solution();
}