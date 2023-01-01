#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,x,y;
int block[4][3][2] = {
  {{0,0},{0,1},{1,0}},
  {{0,0},{0,1},{1,1}},
  {{0,0},{1,1},{1,0}},
  {{0,0},{1,0},{1,-1}},
};
int board[128][128] = {0};
bool fin=false;
int cnt = 1;

void solve(){
  if(fin) return;
  
  int a=-1,b;
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      if (!board[i][j]){
        a = i;
        b = j;
      }
      if (a!=-1) break;
    }
    if (a!=-1) break;
  }
  
  if (a == -1){
    for (int i=0; i<n; i++){
      for (int j=0; j<n; j++)
        cout << board[i][j] << " ";
      cout << endl;
    }
    fin = true;
    return;  
  }

  for (int i=0; i<4; i++){
    int sum = 0;

    for (int j=0; j<3; j++){
      if (a+block[i][j][0]<0 || a+block[i][j][0]>=n || 
        b+block[i][j][1]<0 || b+block[i][j][1]>=n)
        sum = 10000;
      sum += board[a+block[i][j][0]][b+block[i][j][1]];
    }

    if (sum == 0){
      for (int j=0; j<3; j++)
        board[a+block[i][j][0]][b+block[i][j][1]] = cnt;
      cnt++;
      solve();
      for (int j=0; j<3; j++)
        board[a+block[i][j][0]][b+block[i][j][1]] = 0;
      cnt--;
    }
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cin >> n >> x >> y;

  n = pow(2,n);
  int a = x;
  x = n-y;
  y = a-1;
  
  board[x][y] = -1;

  solve();
}