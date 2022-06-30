#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

int board[10][10];
int paper[6]={0,5,5,5,5,5};
int ans;

void cover(int x, int y, int n, int to){
  for (int i=x; i<x+n; i++)
    for (int j=y; j<y+n; j++)
      board[i][j] = to;
}

bool canCover(int x, int y, int n){
  for (int i=x; i<x+n; i++)
    for (int j=y; j<y+n; j++)
      if (!board[i][j])
        return false;
  return true;
}

int solve(){
  int x=-1,y;
  for (int i=0; i<10; i++){
    for (int j=0; j<10; j++)
      if (board[i][j]){
        x = i;
        y = j;
        break;
      }
    if (x != -1) break;
  }
    
  if (x == -1) return 0;

  int ret = 10000;
  
  for (int k=5; k>=1; k--){
    if (x+k <= 10 && y+k <= 10 && canCover(x,y,k) && paper[k]){
      paper[k]--;
      cover(x,y,k,0);
      ret = min(ret, solve()+1);
      paper[k]++;
      cover(x,y,k,1);
    }
  }  

  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  for (int i=0; i<10; i++)
    for (int j=0; j<10; j++)
      cin >> board[i][j];
  
  ans = solve();
  if (ans == 10000) cout << -1;
  else cout << ans;
}