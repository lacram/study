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

/* 
dp
 */

int dp[300002];
int dp2[300002];
int rdp[300002];
int rdp2[300002];
int arr[300002];
int arr2[300002];

int solution() {

  for (int i=0; i<=n+1; i++) {
    dp[i] = -INF;
    dp2[i] = -INF;
    rdp[i] = -INF;
    rdp2[i] = -INF;
  }

  int total = 0;
  int total2 = 0;
  for (int i=1; i<=n; i++) {
    if (total < 0) total = 0;
    if (total2 < 0) total2 = 0;

    total += arr[i];
    dp[i] = max(dp[i-1], total);

    total2 += arr2[i];
    dp2[i] = max(dp2[i-1], total2);
  }

  total = 0;
  total2 = 0;
  for (int i=n; i>=1; i--) {
    if (total < 0) total = 0;
    if (total2 < 0) total2 = 0;

    total += arr[i];
    rdp[i] = max(rdp[i+1], total);

    total2 += arr2[i];
    rdp2[i] = max(rdp2[i+1], total2);
  }

  int ans = -INF;
  for (int i=1; i<=n-1; i++) {
    ans = max(ans, dp[i]+rdp2[i+1]);
    ans = max(ans, rdp[i+1]+dp2[i]);
  }

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  int test;
  cin >> test;

  for (int t=1; t<=test; t++) {
    cin >> n;

    for (int i=1; i<=n; i++) {
      cin >> arr[i];
    }
    for (int i=1; i<=n; i++) {
      cin >> arr2[i];
    }

    cout << "#" << t << " " << solution() << endl;
  }
}