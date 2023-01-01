#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
int memo[1001][1001];
int INF = 10000;

//이모티콘을 S개 만들기 위해 필요한 시간의 최솟값
int solve(int s, int cb) {
  if (s > n || s <= 0) return INF;

  if (s == n) return 0;

  int& ret = memo[s][cb];

  if (ret != -1) return ret;
  ret = INF;
  
  ret = min(ret, solve(s-1, cb)+1);
  if (cb != s) ret = min(ret, solve(s, s)+1);
  if (cb) ret = min(ret, solve(s+cb, cb)+1);

  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  memset(memo, -1 ,sizeof(memo));

  cout << solve(1,0);

}