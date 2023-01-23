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

string a;
string b;
int dp[4000][4000];

int solution() {
  if (a[0] == b[0]) dp[0][0] = 1;

  for (int i=0; i<a.size(); i++)
    for (int j=0; j<b.size(); j++) {
      if (a[i] == b[j]) {
        if (i == 0 || j == 0) dp[i][j] = 1;
        else dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
      }
      else dp[i][j] = 0;
    }
  
  int ans = 0;
  for (int i=0; i<a.size(); i++)
    for (int j=0; j<b.size(); j++)
      ans = max(ans, dp[i][j]);
      
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> a >> b;

  cout << solution();
}