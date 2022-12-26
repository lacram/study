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
vector<int> squareNumbers;

void getSquareNumber() {
  for (int i=1; i*i<=n; i++) {
    squareNumbers.push_back(i*i);
  }
}

int solution() {
  getSquareNumber();

  for (int i=1; i<=n; i++) {
    dp[i] = INF;
    for (int j=0; j<squareNumbers.size(); j++) {
      if (i-squareNumbers[j] >= 0) dp[i] = min(dp[i], dp[i-squareNumbers[j]]+1);
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