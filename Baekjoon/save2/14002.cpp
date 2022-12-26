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
int record[1001];

void getAns(int n) {
  vector<int> v;
  while (n) {
    v.push_back(arr[n]);
    n = record[n];
  }
  reverse(v.begin(), v.end());
  for (auto a : v) {
    cout << a << " ";
  }
}

void solution() {

  for (int i=1; i<=n; i++) {
    dp[i] = 1;
    for (int j=1; j<i; j++) {
      if (arr[j] < arr[i]) {
        if (dp[j]+1 > dp[i]) record[i] = j;
        dp[i] = max(dp[i], dp[j]+1);
      }
    }
  }

  auto it = max_element(dp.begin(), dp.end());
  int idx = it-dp.begin();
  cout << *it << endl;
  getAns(idx);
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

  solution();
}