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

int n,m;
vector<int> adj[210];
int cost[210][210];
int capacity[210][210];
int flow[210][210];
int source,sink;

int solve(){
  
  int ans = 0;

  // 최단 경로를 찾아서 최대 유량 보냄
  while(1){
    int parent[210] = {};
    int total[210];
    bool isInQ[210] = {0};
    for (int i=0; i<210; i++){
      total[i] = INF;
    }
    for (int i=0; i<210; i++){
      parent[i] = -1;
    }
    
    total[source] = 0;
    queue<int> q;
    q.push(source);
    isInQ[source] = true;

    while(!q.empty()) {
      int now = q.front();
      q.pop();
      isInQ[now] = false;

      for (int i=0; i<adj[now].size(); i++){
        int next = adj[now][i];
        if (capacity[now][next] - flow[now][next] > 0 && total[next] > total[now] + cost[now][next]){
          total[next] = total[now] + cost[now][next];
          parent[next] = now;
          if (!isInQ[next]){
            q.push(next);
            isInQ[next] = true;
          }
        }
      }
    }

    if (parent[sink] == -1) break;

    int amount = INF;
    for (int i=sink; i!=source; i=parent[i]){
      amount = min(amount, capacity[parent[i]][i] - flow[parent[i]][i]);
    }
    for (int i=sink; i!=source; i=parent[i]){
      flow[i][parent[i]] -= amount;
      flow[parent[i]][i] += amount;
      ans += amount * cost[parent[i]][i];
    }
    
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  source = 0;
  sink = n+m+1;

  // 사람 to sink
  for (int i=1; i<=n; i++){
    int a;
    cin >> a;
    capacity[m+i][sink] = a;
    adj[m+i].push_back(sink);
    adj[sink].push_back(m+i);
  }
  // source to 서점
  for (int i=1; i<=m; i++){
    int a;
    cin >> a;
    capacity[source][i] = a;
    adj[i].push_back(source);
    adj[source].push_back(i);
  }
  
  for (int i=1; i<=m; i++){
    for (int j=1+m; j<=n+m; j++){
      int a;
      cin >> a;
      cost[i][j] = a;
      cost[j][i] = -a;
      adj[i].push_back(j);
      adj[j].push_back(i);
      capacity[i][j] = INF;
    }
  }

  cout << solve();
}