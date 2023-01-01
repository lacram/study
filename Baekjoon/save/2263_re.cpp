#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#define endl '\n'

using namespace std;

int n;
int inorder[100000];
int postorder[100000];
int pos[100001];

void solve(int is, int ie, int ps, int pe){
  if (is > ie || ps > pe) return;

  int root = postorder[pe];
  cout << root << " ";

  int ir = pos[root]; 

  solve(is, ir-1, ps, ps+ir-is-1);
  solve(ir+1, ie, ps+ir-is, pe-1);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    cin >> inorder[i];
  }

  for (int i=0; i<n; i++){
    cin >> postorder[i];
  }

  for (int i=0; i<n; i++)
    pos[inorder[i]] = i;

  solve(0,n-1,0,n-1);
}