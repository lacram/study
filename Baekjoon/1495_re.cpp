#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,s,m;
int dp[101][1001] = {0};
int arr[100];

int solve(){
  dp[0][s] = 1;

  for (int i=0; i<n; i++){
    for (int j=0; j<=1000; j++)
      if (dp[i][j]){
        if (j+arr[i] <= m) dp[i+1][j+arr[i]] = 1;
        if (j-arr[i] >= 0) dp[i+1][j-arr[i]] = 1;
      }
  }

  for (int i=1000; i>=0; i--)
    if (dp[n][i]){
      return i;
      break;
    }

  return -1;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> s >> m;

  for (int i=0; i<n; i++){
    cin >> arr[i];
  }

  cout << solve();
}