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
long long dp[1000001];

int solution() {
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  for (int i=4; i<=1000000; i++) {
    dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % 1000000009;
  }
  return dp[n];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  int test;
  cin >> test;
    
  solution();
  while (test--) {
    cin >> n;

    cout << dp[n] << endl;
  }
}