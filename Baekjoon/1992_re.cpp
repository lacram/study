#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#define endl '\n'

using namespace std;

int n;
string board[64];

void solve(int x, int y, int n){
  if (n==1){
    cout << board[x][y];
    return;
  }

  for (int i=x; i<x+n; i++)
    for (int j=y; j<y+n; j++)
      if (board[i][j] != board[x][y]){
        cout << "(";
        solve(x,y,n/2);
        solve(x,y+n/2,n/2);
        solve(x+n/2,y,n/2);
        solve(x+n/2,y+n/2,n/2);
        cout << ")";
        return;
      }

  cout << board[x][y];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++)
    cin >> board[i];

  solve(0,0,n);
}