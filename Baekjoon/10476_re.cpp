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

int rsum(int line){
  int total = 0;
  for (int i=line; i<n; i++)
    for (int j=0; j<2; j++)
      total += room[i][j];

  return total;
}

// 왼쪽 닫힘 0, 오른쪽 닫힘 1, 둘다 열림 2
int solve(int line, int toClose, int state){
  if (toClose == 0) return rsum(line);
  if (line == n) return -40000;

  int& ret = dp[line][toClose][state];
  if (ret != -1) return ret;
  ret = -40000;

  if (state != 1) ret = max(ret, solve(line+1,toClose-1,0)+room[line][1]);
  if (state != 0) ret = max(ret, solve(line+1,toClose-1,1)+room[line][0]);
  ret = max(ret, solve(line+1,toClose,2)+room[line][0]+room[line][1]);

  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cin >> n >> k;

  for (int i=0; i<n; i++)
    for (int j=0; j<2; j++)
      cin >> room[i][j];

  memset(dp, -1, sizeof(dp));

  cout << solve(0,k,2);
}