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

/* 
1111
112
121
211
22

111
12
21

11111
1112
1121
1211
2111
122
212
221

dp[5] = dp[4] + dp[3]
1 - 1
2 - 2
3 - 3
4 - 5

 */

int dp[60001];

int solution(int n) {
  dp[1] = 1;
  dp[2] = 2;
  for (int i=3; i<=n; i++) {
    dp[i] = (dp[i-1] + dp[i-2]) %  1000000007;
  }
  return dp[n];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}