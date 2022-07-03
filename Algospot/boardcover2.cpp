#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

int test,h,w,bw,bh;
char board[10][10];
int blockx[4][10];
int blocky[4][10];
char b[10][10];

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cin >> test;
  while(test--){
    cin >> h >> w >> bh >> bw;

    int n = max(bh,bw)-1;

    for (int i=0; i<h; i++)
      for (int j=0; j<w; j++)
        cin >> board[i][j];
    
    for (int i=0; i<bh; i++)
      for (int j=0; j<bw; j++)
        cin >> b[i][j];

    for (int i=0; i<bh; i++)
      for (int j=0; j<bw; j++){
        if (b[i][j] == '#'){
          blockx[0][i] = i;
          blocky[0][j] = j;
          blockx[1][i] = j;
          blocky[1][j] = n-i;
          blockx[2][i] = n-i;
          blocky[2][j] = n-j;
          blockx[3][i] = n-j;
          blocky[3][j] = i;
        }
      }
    
  }
}