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
int dp[100001];
vector<int> arr = {2,5};

int solution() {
  for (int i=1; i<=n; i++) {
    dp[i] = INF;
  }

  for (int i=1; i<=n; i++) {
    for (auto j : arr) {
      if (i >= j) dp[i] = min(dp[i], dp[i-j]+1);
    }
  }
  
  return dp[n] == INF ? -1 : dp[n];
}


int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  cout << solution();
}