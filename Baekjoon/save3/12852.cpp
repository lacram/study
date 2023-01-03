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
int dp[1000001];
int record[1000001];

void print() {
  while (n) {
    cout << n << " ";
    n = record[n];
  }
}

void solution() {
  for (int i=2; i<=n; i++) {
    dp[i] = INF;
  }

  for (int i=1; i<n; i++) {
    if (i*3 <= n) {
      if (dp[i*3] > dp[i]+1) {
        dp[i*3] = dp[i]+1;
        record[i*3] = i;
      }
    }
    if (i*2 <= n) {
      if (dp[i*2] > dp[i]+1) {
        dp[i*2] = dp[i]+1;
        record[i*2] = i;
      }
    }
    if (dp[i+1] > dp[i]+1) {
      dp[i+1] = dp[i]+1;
      record[i+1] = i;
    }
  }

  cout << dp[n] << endl;
  print();
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  solution();
}