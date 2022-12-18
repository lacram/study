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

int n,k;
int dp[20];
int value[100];

int dfs(int money) {
  if (money == 0) return 1;

  int& res = dp[money];
  if (res != -1) return res;

  int tmp = 1;
  for (int i=0; i<n; i++) {
    int nextMoney = money-value[i];
    if (nextMoney >= 0) tmp *= dfs(nextMoney);
  }
  res = tmp;
  return res;
}

int solution() {
  memset(dp, -1, sizeof(dp));

  return dfs(k);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cin >> n >> k;

  for (int i=0; i<n; i++){
    cin >> value[i];
  }

  cout << solution();
}