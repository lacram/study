#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n, cnt=0;
int dp[101][1 << 10][10];

int solve(int idx, int used, int lastN){

  if (n < 10) return 0;
  if (lastN < 0 || lastN > 9) return 0;
  
  int &ret = dp[idx][used][lastN];
  if (ret != -1) return ret;
  
  ret = 0;

  if (idx == n) {
    if (used == (1<<10)-1) return ret = 1;
    return ret;
  }

  ret += solve(idx+1, used | (1<<(lastN-1)), lastN-1);
  ret += solve(idx+1, used | (1<<(lastN+1)), lastN+1);
  
  return ret %= 1000000000;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");
  
  cin >> n;

  memset(dp, -1, sizeof(dp));
  for (int i=1; i<=9; i++){
    cnt += solve(1,1<<i,i);
    cnt %= 1000000000;
  }

  cout << cnt;
}