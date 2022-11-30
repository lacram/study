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

int n,m,k;

int dis[401][401];

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++){
      if (i == j) dis[i][j] = 0;
      else dis[i][j] = INF;
    }

  for (int i=0; i<m; i++){
    int a,b;
    cin >> a >> b;
    dis[a][b] = 1;
  }

  for (int k=1; k<=n; k++)
    for (int i=1; i<=n; i++)
      for (int j=1; j<=n; j++){
          dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
  
  cin >> k;

  for (int i=0; i<k; i++){
    int a,b;
    cin >> a >> b;
    if (dis[a][b] == INF && dis[b][a] == INF) cout << 0;
    else if (dis[a][b] == INF && dis[b][a]) cout << 1;
    else if (dis[a][b] && dis[b][a] == INF) cout << -1;
    cout << endl;
  }
} 