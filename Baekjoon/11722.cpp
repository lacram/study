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
int arr[1001];
vector<int> dp(1001);

int solution() {
  for (int i=1; i<=n; i++) {
    dp[i] = 1;
    for (int j=1; j<=i; j++) {
      if (arr[i] < arr[j]) dp[i] = max(dp[i], dp[j]+1);
    }
  }
  
  return *max_element(dp.begin(), dp.end());
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