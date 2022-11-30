#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#define endl '\n'

using namespace std;

int n;
int board[128][128];
int wh=0, bl=0;

void solve(int x, int y, int t){
  if (t==1) 
    board[x][y] ? bl++ : wh++;

  else{
    for (int i=x; i<x+t; i++)
      for (int j=y; j<y+t; j++)
        if (board[x][y] != board[i][j]){
          solve(x,y,t/2);
          solve(x+t/2,y,t/2);
          solve(x,y+t/2,t/2);
          solve(x+t/2,y+t/2,t/2);
          return;
        }
    board[x][y] ? bl++ : wh++;
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
    for (int j=0; j<n; j++)
      cin >> board[i][j];
  }
  solve(0,0,n);

  cout << wh << endl << bl;
}