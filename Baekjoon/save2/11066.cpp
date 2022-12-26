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
int arr[1000];
int dp[1000][1000];
int record[1000][1000];

/* 
dp[1][n] 
 */

void solution() {
  // 간격
  for (int t=0; t<n; t++) {
    // 시작 위치
    for (int i=1; i<=n; i++) {
      dp[i][i] = 0;
      record[i][i] = arr[i];
      int j = i+t;

      for (int k=i; k<j; k++) {

        if (dp[i][j] > dp[i][k] + dp[k+1][j] + record[i][k] + record[k+1][j]) {
          dp[i][j] = dp[i][k] + dp[k+1][j] + record[i][k] + record[k+1][j];
          record[i][j] = record[i][k] + record[k+1][j];
        }
      }
    }
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  int test;
  cin >> test;

  while (test--) {
    cin >> n;

    for (int i=1; i<=n; i++)
      for (int j=1; j<=n; j++) {
        dp[i][j] = INF;
        record[i][j] = 0;
      }

    for (int i=1; i<=n; i++){
      cin >> arr[i];
    }

    solution();

    cout << dp[1][n] << endl;
  }
}