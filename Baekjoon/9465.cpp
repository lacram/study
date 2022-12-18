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
int arr[100001][2];
int dp[100001][2];

/* 
dp[i][0] = max(dp[i-1][1], dp[i-2][1]) + arr[0]
dp[i][1] = max(dp[i-1][0], dp[i-2][0]) + arr[1]

 */

int solution() {
  dp[1][0] = arr[1][0];
  dp[1][1] = arr[1][1];
  for (int i=2; i<=n; i++) {
    dp[i][0] = max(dp[i-1][1], dp[i-2][1]) + arr[i][0];
    dp[i][1] = max(dp[i-1][0], dp[i-2][0]) + arr[i][1];
  }

  return max(dp[n][0], dp[n][1]);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  int t;
  cin >> t;

  for (int i=0; i<t; i++){
    cin >> n;
    for (int j=0; j<2; j++) {
      for (int k=1; k<=n; k++) {
        cin >> arr[k][j];
      }
    }
    cout << solution() << endl;
  }
}