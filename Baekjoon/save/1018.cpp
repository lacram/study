#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
string bw[8]={
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW"
};
string bb[8] = {
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB"
};
char board[51][51];
//N 세로 M 가로 8~50
int main(){
  int h,w;
  cin >> h >> w;

  for(int i=0; i<h; i++)
    for(int j=0; j<w; j++)
      cin >> board[i][j];
 
  int m = 9999;
  for(int x=0; x<h-7; x++){
    for(int y=0; y<w-7; y++){
      int cntw=0, cntb=0;
      for(int i=x; i<x+8; i++){
        for(int j=y; j<y+8; j++){
          if(board[i][j] != bb[i-x][j-y]) cntb++;
          if(board[i][j] != bw[i-x][j-y]) cntw++;
        }
      }
      m = min(m, min(cntw,cntb));
    }
  }

  cout << m;
}