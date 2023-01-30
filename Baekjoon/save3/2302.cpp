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

int n,m;
int dp[41];
vector<int> vip;

int solution() {
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
	for (int i = 3; i <= 40; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

  int idx = 1;
	int ans = 1;

	for (auto num : vip) {
    ans *= dp[num-idx];
    idx = num+1;
  }
	ans *= dp[n+1 - idx];

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  for (int i=0; i<m; i++) {
    int a;
    cin >> a;
    vip.push_back(a);
  }
	
	cout << solution();
}