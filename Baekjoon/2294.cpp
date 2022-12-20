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
int arr[101];
int dp[10001];

int solution() {
  for (int i=1; i<=k; i++) {
    dp[i] = INF;
  }

  for (int i=1; i<=k; i++) {
    for (int j=1; j<=n; j++) {
      if (i-arr[j] >= 0) dp[i] = min(dp[i], dp[i-arr[j]]+1);
    }
  }

  return dp[k] == INF ? -1 : dp[k];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> k;

  for (int i=1; i<=n; i++){
    cin >> arr[i];
  }

  cout << solution();
}