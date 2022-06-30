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

vector<vector<int>> tree(20);
bool isSheep[20];
int ans = 1;

vector<int> insert(int node, vector<int> nodes) {
  for (auto n : tree[node]) {
    nodes.push_back(n);
  }
  nodes.erase(remove(nodes.begin(), nodes.end(), node), nodes.end());

  return nodes;
}

// 현재 양 수, 늑대 수, 다음에 갈 수 있는 노드
void dfs(int n, int m, vector<int> nodes) {
  ans = max(ans, n);

  if (m >= n) return;

  for (auto node : nodes) {
    vector<int> nodesTmp = insert(node, nodes);

    if (isSheep[node]) dfs(n+1, m, nodesTmp);
    else dfs(n, m+1, nodesTmp);
  }
}

int solution(vector<int> info, vector<vector<int>> edges) {
  for (int i=0; i<info.size(); i++) 
    isSheep[i] = !info[i];

  for (auto edge : edges) {
    int fr = edge[0];
    int to = edge[1];

    tree[fr].push_back(to);
  }

  dfs(1,0,tree[0]);

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution({0,1,0,1,1,0,1,0,0,1,0} ,{{0,1},{0,2},{1,3},{1,4},{2,5},{2,6},{3,7},{4,8},{6,9},{9,10}});

}