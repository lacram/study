#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
int cost[16][16];
int memo[16][65536];

// 현재 now이고 방문한 도시들이 visited일때 나머지 도시를 순회하고 0번 도시로 돌아갈때의 최소비용
int solve(int now, int visited){
  if (visited == (1<<n)-1)
    return cost[now][0] ? cost[now][0] : 20000000;

  int& ret = memo[now][visited];

  if (ret != -1) return ret;
  ret =  20000000;

  for (int i=1; i<n; i++){
    if (visited & (1<<i) || !cost[now][i]) continue;
    ret = min(ret, solve(i, visited | (1<<i))+cost[now][i]);
  }

  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      cin >> cost[i][j];
  
  memset(memo, -1, sizeof(memo));
  cout << solve(0,1);
}