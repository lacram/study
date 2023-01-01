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
int arr[16][2];
vector<int> dp(16);

/* 
 */

int solution() {
  for (int i=1; i<=n+1; i++) {
    for (int j=1; j<=i; j++) {
      int workTime = arr[j][0];
      int pay = arr[j][1];
      if (j + workTime <= i) {
        dp[i] = max(dp[i], dp[j]+pay);
      }
    }
  }
  return dp[n+1];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=1; i<=n; i++){
    for (int j=0; j<2; j++) {
      cin >> arr[i][j];
    }
  }

  cout << solution();
}