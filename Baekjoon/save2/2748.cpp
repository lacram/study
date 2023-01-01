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
long long dp[100];

long long fibonacci(int t) {
  if (t == 0) return 0;
  if (t == 1) return 1;
  if (dp[t]) return dp[t];
  return dp[t] = fibonacci(t-1) + fibonacci(t-2);
}

long long solution() {
  return fibonacci(n);
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