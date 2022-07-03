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

vector<vector<int>> tree;
vector<int> treeVal;
vector<bool> used;
int root;

// pair<int,int>
// 그룹개수, 합

// 합이 작은 pair 반환
pair<int,int> min(pair<int,int> p1, pair<int,int> p2){
  return p1.second < p2.second ? p1 : p2;
}

pair<int,int> dfs(int now, int num){
  if (now == -1) return {1, 0};
  if (treeVal[now] > num) return {10001, 0};

  pair<int,int> left = dfs(tree[now][0],num);
  pair<int,int> right = dfs(tree[now][1],num);

  // parent + all child
  if (treeVal[now] + left.second + right.second <= num){
    // 합쳐지면서 1개가 줄음
    return {left.first+right.first-1, treeVal[now] + left.second + right.second};
  }
  // parent + left or right child
  else if (treeVal[now] + left.second <= num || treeVal[now] + right.second <= num) {
    pair<int,int> p = min(left,right);
    return {left.first+right.first, treeVal[now] + p.second};
  }
  // parent, left, right
  else {
    return {left.first+right.first+1, treeVal[now]};
  }
}

int solution(int k, vector<int> num, vector<vector<int>> links) { 
  int n = links.size();
  tree.resize(n);
  treeVal.resize(n);
  used.resize(n);
  
  for (int i=0; i<links.size(); i++) {
    treeVal[i] = num[i];
    for (int j=0; j<2; j++){
      int node = links[i][j];
      tree[i].push_back(node);
      if (node != -1) used[node] = 1;
    }
  }
   
  // 루트 찾기
  for (int i=0; i<n; i++) 
    if (!used[i])
      root = i;
  
  int lo = 1; 
  int hi = 100000000;

  while (lo <= hi) {
    int mid = (lo+hi)/2;
    if (dfs(root,mid).first <= k) hi = mid-1;
    else lo = mid+1;
  }
  return lo;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution(4, {3,2,5,4,1,4,3,3,5,2,2,3,1},{{1,2},{3,4},{5, -1},{6,7},{8,9},{10,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{11,12},{-1,-1},{-1,-1}} );

}