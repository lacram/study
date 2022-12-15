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
int dp[1001][1001];
string str1,str2;

int solution() {
  for (int i=1; i<=str1.size(); i++)
    for (int j=1; j<=str2.size(); j++) {
      if (str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }

  return dp[str1.size()][str2.size()];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> str1 >> str2;

  cout << solution();
}