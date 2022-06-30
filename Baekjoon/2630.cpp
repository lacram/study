#include <iostream>
#include <fstream>
using namespace std;

int board[128][128];
int blue=0, white=0;

void solve(int x, int y, int n){
  int srt = board[x][y];
  
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      if(srt != board[x+i][y+j]){
        solve(x,y,n/2);
        solve(x,y+n/2,n/2);
        solve(x+n/2,y,n/2);
        solve(x+n/2,y+n/2,n/2);
        return;
      }
  if (srt == 1) blue++;
  else white++;
}

int main(){
  int n;
  cin >> n;
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      cin >> board[i][j];
  
  solve(0,0,n);
  cout << white << endl;
  cout << blue;
      
}