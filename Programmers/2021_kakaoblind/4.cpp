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
#define INF 100000000

using namespace std;

int road[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
  
  for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++){
      if (i != j) road[i][j] = INF;
    }
  
  for (auto fare : fares) {
    int a = fare[0];
    int b = fare[1];  
    int cost = fare[2];

    road[a][b] = cost;
    road[b][a] = cost;
  }

  // 플로이드 와샬
  for (int k=1; k<=n; k++)
    for (int i=1; i<=n; i++)
      for (int j=1; j<=n; j++) {
        if (road[i][j] > road[i][k] + road[k][j])
          road[i][j] = road[i][k] + road[k][j];
      }

  int ans = INF;
  for (int i=1; i<=n; i++) {
    ans = min(ans, road[s][i] + road[i][a] + road[i][b]);
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