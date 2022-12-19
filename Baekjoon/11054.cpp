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
int rdp[1001];
int arr[1001];

int solution() {
  for (int i=1; i<=n; i++) {
    dp[i] = 1;
    rdp[i] = 1;
  }

  for (int i=1; i<=n; i++) {
    for (int j=i+1; j<=n; j++) {
      if (arr[i] < arr[j]) dp[j] = max(dp[j], dp[i] + 1);
    }
  }

  for (int i=n; i>=1; i--) {
    for (int j=i-1; j>=1; j--) {
      if (arr[i] < arr[j]) rdp[j] = max(rdp[j], rdp[i] + 1);
    }
  }

  int ans = 0;
  for (int i=1; i<=n; i++) {
    ans = max(ans, dp[i]+rdp[i]);
  }
  return ans-1;
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