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

int dp[10001];
int value[100];
int n,k;

int solution() {
  dp[0] = 1;
  for (int i=0; i<n; i++)
    for (int j=1; j<=k; j++) {
      if (j-value[i] >= 0) dp[j] += dp[j-value[i]];
    }
  
  return dp[k];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cin >> n >> k;

  for (int i=0; i<n; i++){
    cin >> value[i];
  }

  cout << solution();
}