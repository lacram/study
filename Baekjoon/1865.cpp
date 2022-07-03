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

int n,m,w;
vector<pair<int,int>> adj[501];
vector<long long> upper(501, INF);

bool ballmanFord(int srt){
  upper[srt] = 0;
  bool updated;

  for (int i=0; i<n; i++) {
    updated = false;
    for (int now=1; now<=n; now++) {
      for (int j=0; j<adj[now].size(); j++) {
        int next = adj[now][j].first;
        long long cost = adj[now][j].second;

        if (upper[next] > upper[now] + cost){
          upper[next] = upper[now] + cost;
          updated = true;
        }
      }
    }
    if (!updated) break;
  }
  return !updated;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  int test;
  cin >> test;

  while (test--){
    for (int i=1; i<=n; i++){
      adj[i].clear();
      upper[i] = INF;
    }

    cin >> n >> m >> w;

    for (int i=0; i<m; i++){
      int a,b,c;
      cin >> a >> b >> c;
      adj[a].push_back({b,c});
      adj[b].push_back({a,c});
    }

    for (int i=0; i<w; i++){
      int a,b,c;
      cin >> a >> b >> c;
      adj[a].push_back({b,-c});
    }

    if (ballmanFord(1)){
      cout << "NO" << endl;
    }
    else {
      cout << "YES" << endl;
    }
  }
}
