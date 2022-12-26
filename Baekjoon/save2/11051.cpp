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
int dp[1001][1001];

int solution() {
  dp[1][0] = 1;
  dp[1][1] = 1;
  for (int i=2; i<=n; i++)
    for (int j=0; j<=i; j++)
      dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
  
  return dp[n][k];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> k;

  cout << solution();
}