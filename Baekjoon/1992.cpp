#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#define endl '\n'

using namespace std;

int n;
string board[64];

void solve(int x, int y, int t){
  if (t==1) 
    cout << board[x][y];

  else{
    for (int i=x; i<x+t; i++)
      for (int j=y; j<y+t; j++)
        if (board[x][y] != board[i][j]){
          cout << "(";
          solve(x,y,t/2);
          solve(x,y+t/2,t/2);
          solve(x+t/2,y,t/2);
          solve(x+t/2,y+t/2,t/2);
          cout << ")";
          return;
        }
    cout << board[x][y];
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    cin >> board[i];
  }
  
  solve(0,0,n);

}