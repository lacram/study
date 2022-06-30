#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <cmath>

using namespace std;

int INF = 20000000;
int n;
int cost[16][16];
int cache[16][65536];

int solve(int now, int visit){
  // 모든도시 방문시 종료
  if (visit == (1 << n)-1) {
    if (cost[now][0]) return cost[now][0];
    else return INF;
  }

  int &ret = cache[now][visit];
  if (ret != -1) return ret;

  ret = INF;
  for (int next=0; next<n; next++){
    
    // 이미 방문한 도시
    if (visit & (1 << next)) continue;

    // 길이 있는경우 방문
    if (cost[now][next] != 0){
      int cand = solve(next, visit + (1 << next)) + cost[now][next];
      ret = min(ret, cand);
    }
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
  
  for (int i=0; i<n; i++)
    for (int j=0; j<pow(2,n); j++)  
      cache[i][j] = -1;

  cout << solve(0,1);
}