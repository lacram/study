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

void solve(int is, int ie, int ps, int pe){
  if (ps > pe || is > ie) return;
  
  int root = postorder[pe];
  cout << root << " ";

  int idxi;
  for (int i=0; i<n; i++)
    if (inorder[i] == root){
      idxi = i;
      break;
    }
  
  int dif = idxi-is;

  solve(is,idxi-1,ps,ps+dif-1);
  solve(idxi+1,ie,ps+dif,pe-1);
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

  solve(0,n-1,0,n-1);
}