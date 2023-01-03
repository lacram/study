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
int dp[101][10001];
int memory[101];
int cost[101];

/* 
비활성화 비용 기준 dp
0~10000
같은 비용 기준 메모리 양이 많아야됨
 */

int solution() {

  // 물품
  for (int i=1; i<=n; i++) {
    // 비활성화 비용
    for (int j=0; j<=10000; j++) {
      if (cost[i] <= j) dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]] + memory[i]);
      else dp[i][j] = dp[i-1][j];
    }
  }

  for (int i=0; i<=10001; i++) {
    if (dp[n][i] >= m) return i;
  }
    
  return -1;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  for (int i=1; i<=n; i++){
    cin >> memory[i];
  }
  for (int i=1; i<=n; i++){
    cin >> cost[i];
  }

  cout << solution();
}