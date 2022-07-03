#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int board[22][22];
int h, w, ret=0, cntWhite=0;
int shape[4][3][2] = {
  {{0,0},{0,1},{1,0}},
  {{0,0},{0,1},{1,1}},
  {{0,0},{1,0},{1,1}},
  {{0,0},{1,0},{1,-1}}
};
void printb(){
  cout << endl;
  for(int i=0; i<h+2; i++){
    for(int j=0; j<w+2; j++)
      cout << board[i][j];
    cout << endl;
  }
}
bool canCover(int x, int y,int k){
  for(int i=0; i<3; i++){
    int cx = shape[k][i][0]+x, cy = shape[k][i][1]+y;
    if(board[cx][cy]==0)
     return false;
  }
  return true;
}
void cover(int x, int y,int k, int n){
  for(int i=0; i<3; i++){
    int cx = shape[k][i][0]+x, cy = shape[k][i][1]+y;
    board[cx][cy] = n;
  }
}

void coverAll(){
  int x=-1,y;
  for(int i=1; i<h+1; i++){
    for(int j=1; j<w+1; j++){
      if(board[i][j]==1) {
        x=i; y=j; break;
      }
    }
    if (x!=-1) break;
  }
  if (x==-1){
    ret++;
    return;
  }
  
  for(int k=0; k<4; k++){
    if(canCover(x,y,k)){
      cover(x,y,k,0);
      coverAll();
      cover(x,y,k,1);
    }
  }
}

int main(){
  int test;
  cin >> test;

  while (test--){
    memset(board, 0, sizeof(board));
    cntWhite=0;
    ret = 0;
    
    cin >> h >> w;

    for(int i=1; i<h+1; i++)
      for(int j=1; j<w+1; j++){
        char c;
        cin >> c;
        if (c == '.'){ 
          board[i][j] = 1;
          cntWhite++;
        }
      }
      
    if (cntWhite % 3 != 0) {
      cout << 0 << endl;
    }
    else {
      coverAll();
      cout << ret << endl;
    }
  }
}