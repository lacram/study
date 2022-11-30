#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
int node;
vector<int> child[50];

int solve(int root){

  if (child[root].empty()) return 1;

  int ret = 0;

  for (int i=0; i<child[root].size(); i++){
    if (child[root][i] == node) {
      if (child[root].size() == 1) ret++;
      continue;
    }
    ret += solve(child[root][i]);
  }

  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;
  int root;

  for (int i=0; i<n; i++){
    int parent;
    cin >> parent;
    
    if (parent == -1) {
      root = i;
      continue;
    }

    child[parent].push_back(i);
  }
  cin >> node;

  if (root == node) cout << 0;
  else cout << solve(root);
}