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
int arr[100001];
vector<int> dp(100001);
vector<int> dp2(100001);

int solution() {
  dp[1] = 1;
  dp2[1] = 1;
  for (int i=2; i<=n; i++) {
    dp[i] = 1;
    dp2[i] = 1;
    if (arr[i-1] <= arr[i]) dp[i] = max(dp[i], dp[i-1]+1);
    if (arr[i-1] >= arr[i]) dp2[i] = max(dp2[i], dp2[i-1]+1);
  }
  return max(*max_element(dp.begin(), dp.end()), *max_element(dp2.begin(), dp2.end()));
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