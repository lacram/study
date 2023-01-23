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
int dp[100001][4];

/* 
i를 합으로 나타낼때 j가 마지막인 경우의 수
dp[i][j]

 */

void solution() {

  dp[1][1] = 1;
  dp[2][2] = 1;
  dp[3][3] = 1;

  for (int i=1; i<100001; i++)
    for (int j=1; j<=3; j++) {
      if (i > j)
        for (int k=1; k<=3; k++)
          if (j != k) {
            dp[i][j] += dp[i-j][k];
            dp[i][j] %= 1000000009;
          }
    }
}

int getAns() {
  int ans = 0;
  for (int i=1; i<=3; i++) {
    ans += dp[n][i];
    ans %= 1000000009;
  }
  return ans;
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
  for (int i=0; i<test; i++){
    cin >> n;
    cout << getAns() << endl;
  }
}