#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,m,t,fr,to;
vector<pair<int,int>> weight[100010];
long long dp[100010][20];

long long solve(int now, int k){

  if (now == to && k == 0) return 0;

  long long& ret = dp[now][k];
  if (ret != -1) return ret;
  ret = -10000000000000000;

  for (int i=0; i<weight[now].size(); i++){
    if (weight[now][i].second == 0 && k > 0) {
      ret = max(ret, solve(weight[now][i].first, k-1)+weight[now][i].second);
    }
    if (weight[now][i].second != 0)
      ret = max(ret, solve(weight[now][i].first, k)+weight[now][i].second);
  }

  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m >> t >> fr >> to;

  for (int i=0; i<m; i++){
    int a,b,w;
    cin >> a >> b >> w;
    weight[a].push_back({b,w});
    weight[b].push_back({a,0});
  }

  for (int i=0; i<=n; i++)
    for (int j=0; j<=t; j++)
      dp[i][j] = -1;

  long long ans = solve(fr,t);

  if (ans < 0) cout << -1;
  else cout << ans;
}