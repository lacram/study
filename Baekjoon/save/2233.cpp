#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
int x[2];
int y[2];
string str;
vector<vector<int>> tree;
int depth[2001];
int par[2001];

void setDepth(int root, int d){
  for (int node : tree[root]){
    depth[node] = d;
    setDepth(node, d+1);
  }
}

int solve(){
  int a = y[0];
  int b = y[1];

   while (depth[a] > depth[b]){
    a = par[a];
  }
  while (depth[a] < depth[b]){
    b = par[b];
  }

  while (a != b){
    a = par[a];
    b = par[b];
  }

  return a;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;
  tree.resize(n+1);
  cin >> str;

  cin >> x[0] >> x[1];

  int parent = 0;
  int child = 1;
  for (int i=0; i<str.length(); i++){

    if (str[i] == '0') {
      for (int j=0; j<2; j++){
        if (i == x[j]-1) y[j] = child;
      }
      tree[parent].push_back(child);
      par[child] = parent;
      parent = child;
      child++;
    }
    else {
      for (int j=0; j<2; j++){
        if (i == x[j]-1) y[j] = parent;
      }
      parent = par[parent];
    }
  }

  setDepth(1,2);

  int node = solve();
  if (node == 0) node = 1;

  parent = 0;
  child = 1;
  bool find = false;
  for (int i=0; i<str.length(); i++){
    if (str[i] == '0') {
      parent = child;
      child++;
      if (node == parent && !find) {
        find = true;
        cout << i+1 << " ";
      }
    }
    else {
      if (node == parent) {
        cout << i+1;
        break;
      }
      parent = par[parent];
    }
  }
}