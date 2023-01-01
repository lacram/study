#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

int n;
int board[128][128];
int color[2]={0};

void solve(int x, int y, int n){
  int srt = board[x][y];
  if (n == 1) {
    color[srt]++;
    return;
  }

  for (int i=x; i<x+n; i++)
    for (int j=y; j<y+n; j++){
      if (board[i][j] != srt){
        solve(x,y,n/2);
        solve(x,y+n/2,n/2);
        solve(x+n/2,y,n/2);
        solve(x+n/2,y+n/2,n/2);
        return;
      }
    }
  color[srt]++;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  // ifstream cin;
  // cin.open("input.txt");
  
  cin >> n;

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      cin >> board[i][j];
  
  solve(0,0,n);
  
  cout << color[0] << endl << color[1];
}