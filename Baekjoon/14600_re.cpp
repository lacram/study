#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,a,b;
int cnt=1;
int board[128][128]={0};
int check = 0;

void solve(int x, int y, int hx, int hy, int n){
  if (n==1) 
    return;

  int arr[4]={0};

  if (x <= hx && hx < x+n/2 && y <= hy && hy < y+n/2){
    arr[0] = 1;
  }
  if (x <= hx && hx < x+n/2 && y+n/2 <= hy){
    arr[1] = 1;
  }
  if (x+n/2 <= hx && y <= hy && hy < y+n/2){
    arr[2] = 1;
  }
  if (x+n/2 <= hx && y+n/2 <= hy) {
    arr[3] = 1;
  }

  if (!arr[0]) board[x+n/2-1][y+n/2-1] = cnt;
  if (!arr[1]) board[x+n/2-1][y+n/2] = cnt;
  if (!arr[2]) board[x+n/2][y+n/2-1] = cnt;
  if (!arr[3]) board[x+n/2][y+n/2] = cnt;
  cnt++;
  

  if (!arr[0]) solve(x,y,x+n/2-1,y+n/2-1,n/2);
  else solve(x,y,hx,hy,n/2);
  if (!arr[1])solve(x,y+n/2,x+n/2-1,y+n/2,n/2);    
  else solve(x,y+n/2,hx,hy,n/2);
  if (!arr[2])solve(x+n/2,y,x+n/2,y+n/2-1,n/2);
  else solve(x+n/2,y,hx,hy,n/2);
  if (!arr[3])solve(x+n/2,y+n/2,x+n/2,y+n/2,n/2);
  else solve(x+n/2,y+n/2,hx,hy,n/2);
  
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> a >> b;

  n = pow(2,n);
  int t = a;
  a = n-b;
  b = t-1;

  board[a][b] = 1; 

  solve(0,0,a,b,n);

  board[a][b] = -1; 

  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      if (board[i][j]>9) cout << board[i][j] << " ";
      else cout << board[i][j] << "  ";
    }
    cout << endl;
  }
}