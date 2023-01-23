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
int dp[1001];
int arr[1001];

int solution() {
  for (int i=2; i<=1000; i++) {
    dp[i] = INF;
  }

  for (int i=1; i<=n; i++) {
    for (int j=1; j<=arr[i]; j++) {
      if (i+j <= n) dp[i+j] = min(dp[i+j], dp[i]+1);
    }
  }
  return dp[n] == INF ? -1 : dp[n];
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