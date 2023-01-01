#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#define endl '\n'

using namespace std;

int dx[8] = {0,1,1,2,2,2,2,2};
int dy[8] = {0,-1,1,-2,-1,0,1,2};
char board[3072][6143];

void solve(int x, int y, int n){
  if (n==3){
    for (int i=0; i<8; i++)
      board[x+dx[i]][y+dy[i]] = '*';
  }
  else{
    solve(x,y,n/2);
    solve(x+n/2,y+n/2,n/2);
    solve(x+n/2,y-n/2,n/2);
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  int n;

  cin >> n;

  for (int i=0; i<n; i++)
    for (int j=0; j<n*2-1; j++)
      board[i][j] = ' ';

  solve(0,n-1,n);

  for (int i=0; i<n; i++){
    for (int j=0; j<n*2-1; j++)
      cout << board[i][j];
    cout << endl;
  }
    
}