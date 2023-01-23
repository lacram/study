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
int dp[50];
int cnta = 1,cntb;

int fibonacci(int k) {
  if (k == 2 || k == 1) return 1;
  cnta++;

  return fibonacci(k-1) + fibonacci(k-2);
}

int fibonacciDP(int k) {
  if (k == 1) return 1;
  if (k == 2) return 1;

  int& ret = dp[k];
  if (ret != -1) return ret;
  cntb++;
  return ret = fibonacciDP(k-1) + fibonacciDP(k-2);
}

void solution() {
  memset(dp, -1, sizeof(dp));
  fibonacci(n);
  fibonacciDP(n);
  cout << cnta << " " << cntb;
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