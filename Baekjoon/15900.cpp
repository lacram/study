#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
long long ans;
vector<int> tree[500001];

void solve(int depth, int me, int parent){
  if (tree[me].size() == 1 && me != 1){
    ans += depth;
    return;
  }

  for (int i=0; i<tree[me].size(); i++){
    if (tree[me][i] != parent)
      solve(depth+1, tree[me][i], me);
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n-1; i++){
    int a,b;
    cin >> a >> b;

    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  solve(0,1,0);

  if (ans % 2 == 1) cout << "Yes";
  else cout << "No";
}