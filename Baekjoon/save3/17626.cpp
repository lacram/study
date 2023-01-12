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
int dp[50001];

vector<int> squareNumbers;

void makeSquareNumber() {
  for (int i=1; i*i<=50000; i++) {
    squareNumbers.push_back(i*i);
  }
}

int solution() {
  for (int i=1; i<=n; i++) {
    dp[i] = INF;
  }
  makeSquareNumber();

  for (int i=1; i<=n; i++) {
    for (auto squareNumber :squareNumbers) {
      if (i >= squareNumber) dp[i] = min(dp[i], dp[i - squareNumber] + 1);
    }
  }
  return dp[n];
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