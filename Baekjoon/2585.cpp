#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#define endl '\n'

using namespace std;

int n,k,des;
vector<pair<int,int>> v;
int dist[1002][1002];
int visited[1002];

int getDistance(pair<int,int> p1, pair<int,int> p2){
  int x1 = p1.first;
  int y1 = p1.second;
  int x2 = p2.first;
  int y2 = p2.second;

  return ceil(sqrt(pow(x1-x2,2)+pow(y1-y2,2))/10);
}

bool decision(int given){
  queue<pair<int,int>> q;
  q.push({0,k});

  while (!q.empty()){
    int now = q.front().first;
    int cnt = q.front().second;
    q.pop();

    if (dist[now][des] <= given) return true;
    if (cnt <= 0) continue;
    if (visited[now]) continue;
    
    visited[now] = 1;
    for (int next=1; next<=n; next++){
      if (dist[now][next] > given) continue;

      q.push({next,cnt-1});
    }
  }
  return false;
}

int solve(){
  int lo = 1;
  int hi = 1500;

  while (lo <= hi){
    int mid = (lo+hi)/2;
    memset(visited,0,sizeof(visited));

    if (decision(mid)) hi = mid-1;
    else lo = mid+1;
  }

  return lo;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> k;

  v.resize(n+2);
  v[0] = {0,0};
  v[n+1] = {10000,10000};

  for (int i=1; i<=n; i++){
    int a,b;
    cin >> a >> b;

    v[i] = {a,b};
  }

  for (int i=0; i<=n+1; i++)
    for (int j=i+1; j<=n+1; j++){
      int dis = getDistance(v[i],v[j]);
      dist[i][j] = dis;
      dist[j][i] = dis;
    }

  des = n+1;

  cout << solve();
}