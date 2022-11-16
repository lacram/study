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

/* 
0 : 6
1 : 2
2 : 5
3 : 5 
4 : 4
5 : 5
6 : 6
7 : 3
8 : 7
9 : 6

2 3 4 5 5 5 6 6 6 7

9 2+7 -> 2
  4+5.1
  4+5.2
  4+5.3
  5.2+4
  5.3+4 -> 5
  2 3 4

1. dfs
2. 0시작 제외(idx 6이 0임)
 */

int num[10] = {2,3,4,5,5,5,6,6,6,7};
long long dp[51];
long long ans;

long long dfs(int depth, int k) {
  if (k == 0) {
    return 1;
  }

  if (k < 0) return 0;

  long long &ans = dp[k];
  if (ans != -1) return ans;
  ans = 0;

  for (int i=0; i<10; i++) {
    // 목표가 5가 아닐 때 0시작 제외
    if (i == 6 && depth == 0 && k != 6) continue;

    ans += dfs(depth+1, k-num[i]);
  }

  return ans;
}

long long solution(int k) {
  for (int i=0; i<51; i++)
    dp[i] = -1;

  return dfs(0, k);
} 

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution(9);

}