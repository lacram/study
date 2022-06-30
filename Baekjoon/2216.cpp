#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

int a,b,c;
string x, y;
int dp[3001][3001];

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> a >> b >> c;

  cin >> x >> y;

  for (int i=0; i<=x.length(); i++)
    dp[i][0] = b * i;
  for (int i=0; i<=y.length(); i++)
    dp[0][i] = b * i;
  
  for (int i=1; i<=x.length(); i++)
    for (int j=1; j<=y.length(); j++){
      int penalty = c;
      if (x[i-1] == y[j-1]) penalty = a;
      dp[i][j] = max(dp[i-1][j-1] + penalty, dp[i-1][j]+b);
      dp[i][j] = max(dp[i][j], dp[i][j-1]+b);
    }

  cout << dp[x.length()][y.length()];
}