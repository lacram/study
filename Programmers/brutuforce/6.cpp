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

vector<int> childNum;
vector<vector<int>> tree;

int getChildNum(int root) {
  int cnt = 0;
  for (auto node : tree[root]) {
    cnt += getChildNum(node);
  }
  return childNum[root] = cnt+1;
}

int solution(int n, vector<vector<int>> wires) {
  childNum.resize(n+1);
  tree.resize(n+1);

  for (auto wire : wires) {
    tree[wire[0]].push_back(wire[1]);
  }
  
  getChildNum(1);

  int ans = INF;
  for (auto num : childNum) {
    ans = min(ans, abs(n-num-num));
  }

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}