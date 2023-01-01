#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <queue>

using namespace std;

int n,m,fr,to;
vector<pair<int,int>> v[10001];

bool dfs(int t){
  queue<int> q;
  q.push(fr);
  int visited[10001] = {0};
  visited[fr] = 1;
  
  while(!q.empty()){
    int now = q.front();
    q.pop();

    if (now == to) return true;

    for (int i=0; i<v[now].size(); i++){
      int next = v[now][i].first;
      if (!visited[next] && v[now][i].second >= t){
        visited[next] = 1;
        q.push(next);
      }
    }
  }
  return false;
}

int solve(){
  int left = 1;
  int right = 1000000000;

  while (left <= right){
    int mid = (left+right)/2;

    if(dfs(mid)) left = mid+1;
    else right = mid-1;
  }

  return right;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  for (int i=0; i<m; i++){
    int a,b,c;
    cin >> a >> b >> c;
    v[a].push_back(make_pair(b,c));
    v[b].push_back(make_pair(a,c));
    
  }
  cin >> fr >> to;

  cout << solve();
}