#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
vector<vector<int>> tree;
bool visited[17];

void makeTree(vector<vector<int>> edges, int n){
  tree.resize(n);

  for (auto edge : edges){
    tree[edge[0]].push_back(edge[1]);
    tree[edge[1]].push_back(edge[0]);
  }
}

// can : 추가가능한 늑대 수
int dfs(vector<int> info, int now, int can){
  visited[now] = 1;
  int ret = 0;

  for (auto child : tree[now]){
    if (visited[child]) continue;
    // 자식이 늑대일 경우
    if (info[child]){
      if (can >= 1)
        ret = max(ret, dfs(info,child,can-1));
    }
    // 자식이 양
    else{
      ret = max(ret, dfs(info,child,can)+1);
    }
  }
  return ret;
}

int solution(vector<int> info, vector<vector<int>> edges) {
  makeTree(edges, info.size());

  return dfs(info,0,1)+1;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution({0,0,1,1,1,0,1,0,1,0,1,1}, {{0,1},{1,2},{1,4},{0,8},{8,7},{9,10},{9,11},{4,3},{6,5},{4,6},{8,9}});

}