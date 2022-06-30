#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,m,cnt;
vector<vector<int>> tree;
int discoverd[100001];
vector<pair<int,int>> ans;

// (u,v)가 단절선이려면 
// v를 루트로하는 서브트리에서의 역방향 간선으로 가는 노드가 u보다 작아야함
int dfs(int now, int parent){

  int ret = discoverd[now] = ++cnt;

  for (auto next : tree[now]){
    if (next == parent) continue;

    // 방문한 적 없음
    if (!discoverd[next]){
      int df = dfs(next,now);
      if (df > discoverd[now]){
        int a = min(now,next);
        int b = max(now,next);
        ans.push_back({a,b});
      }
      ret = min(ret, df);
    }
    else{
      ret = min(ret, discoverd[next]);
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

  cin >> n >> m;

  tree.resize(n+1);

  for (int i=0; i<m; i++){
    int a,b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  dfs(1,0);

  sort(ans.begin(),ans.end());

  cout << ans.size() << endl;
  for (auto a: ans)
    cout << a.first << " " << a.second << endl;
}