#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#define endl '\n'
#define INF 2000000000

using namespace std;

/* 
리프노드부터 기준에 맞춰 코드 조절
 */

vector<vector<int>> tree;
vector<int> treeVal;
vector<int> limits;
int ans;

int dfs(int now, int k) {

  int val = treeVal[now];
  for (auto child : tree[now]) {
    val += dfs(child,k);
  }
  if (val > limits[now]) {
    int cnt = (val-1 - limits[now]) / k + 1;
    ans += cnt;
    val -= cnt*k;
  }
  return val;
}

int solution(int k, vector<int> l, vector<vector<int>> sockets) {
  limits = l;
  tree.resize(sockets.size());
  treeVal.resize(sockets.size());

  for (int i=0; i<sockets.size(); i++)
    for (int j=0; j<sockets[i].size(); j++) {
      int node = sockets[i][j];
      if (node > 0) tree[i].push_back(node-1);
      if (node == -1) treeVal[i] += k;
    }
  
  dfs(0,k);
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution(120 ,    {1500, 300, 250, 359, 600}  ,    {{2, 3, 4, 0, -1}, {0, 0, 0, 0, 0}, {-1, -1, -1, 0, 0}, {0, 0, 5, 0, 0}, {-1, 0, 0, -1, -1}} );

}