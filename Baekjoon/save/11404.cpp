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
#define INF 10000000000

using namespace std;

int n,m;
long long cost[101][101];

void solve(){
  

  for (int k=1; k<=n; k++)
    for (int i=1; i<=n; i++)
      for (int j=1; j<=n; j++){
          cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
        }

  for (int i=1; i<=n; i++){
    for (int j=1; j<=n; j++){
      if (cost[i][j] == INF) cout << 0 << " ";
      else cout << cost[i][j] << " ";
    }
    cout << endl;
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++){
      if (i == j) cost[i][j] = 0;
      else cost[i][j] = INF;
    }

  for (int i=0; i<m; i++){
    int a,b,c;
    cin >> a >> b >> c;
    if (cost[a][b] > c) cost[a][b] = c;
  }

  solve();
}