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
int arr[21];
int dp[10001];
int money;

int solution() {
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;

  for (int i=1; i<=n; i++) {
    for (int j=1; j<=money; j++) {
      if (j >= arr[i]) dp[j] += dp[j-arr[i]];
    }
  }
  return dp[money];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  int test;
  cin >> test;
  while (test--) {
    cin >> n;

    for (int i=1; i<=n; i++){
      cin >> arr[i];
    }

    cin >> money;

    cout << solution() << endl;
  }

}