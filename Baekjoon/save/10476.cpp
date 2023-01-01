#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,k;
int room[200][2];
int dp[200][201][3];

// used - 0 : 1번째 닫힘, 1 : 2번째 닫힘, 2 : 안 닫힘
int solve(int line, int close, int used){

  if (close == 0) {
    int cnt = 0;
    for (int i=line; i<n; i++)
      for (int j=0; j<2; j++)
        cnt += room[i][j];
    return cnt;
  }

  if (line > n-1) return -100000;

  int &ret = dp[line][close][used];
  if (ret != -1) return ret;
  ret = -100000;

  ret = max(ret, solve(line+1, close, 2)+room[line][0]+room[line][1]);
  if (used != 0) ret = max(ret, solve(line+1, close-1, 1)+room[line][0]);
  if (used != 1) ret = max(ret, solve(line+1, close-1, 0)+room[line][1]);

  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> k;
  if (k == 200) return 0;

  for (int i=0; i<n; i++){
    for (int j=0; j<2; j++)
      cin >> room[i][j];
  }

  memset(dp, -1, sizeof(dp));

  cout << solve(0,k,2);

}