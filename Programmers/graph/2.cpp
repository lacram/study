#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#define endl '\n'
#define INF 2000000000

using namespace std;

bool record[101][101];

int solution(int n, vector<vector<int>> results) {
  for (auto result : results) {
    int winner = result[0];
    int loser = result[1];

    record[winner][loser] = 1;
  }
  for (int k=1; k<=n; k++)
    for (int i=1; i<=n; i++)
      for (int j=1; j<=n; j++) {
        if (record[i][k] && record[k][j]) {
          record[i][j] = 1;
        }
      }
  
  int ans = 0;
  for (int i=1; i<=n; i++) {
    int cnt = 0;
    for (int j=1; j<=n; j++) {
      if (record[i][j] || record[j][i]) cnt++;
    }
    if (cnt == n-1) ans++;
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}