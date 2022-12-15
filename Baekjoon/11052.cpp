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
int arr[10001];
int dp[1001];

/* 
카드개수 i
dp[i]
 */


int solution() {

  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++){
      if (i-j >= 0) dp[i] = max(dp[i], dp[i-j] + arr[j]);
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

  for (int i=1; i<=n; i++){
    cin >> arr[i];
  }

  cout << solution();
}