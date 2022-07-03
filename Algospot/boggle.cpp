#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int memo[6][6][11];
int isPos;
string a;
char board[5][5];
int pos[8][2]={
  {-1,-1},{-1,0},{-1,1},
  {0,-1},{0,1},
  {1,-1},{1,0},{1,1}
};

void find(int x, int y, int cnt){
  if(isPos>0) return;
  if (cnt == a.length()){
    isPos++;
    return;
  }
  memo[x][y][cnt] = 1;

  int cx, cy;
  // 첫단어
  if (cnt==0){
    for(int i=0; i<5; i++)
      for(int j=0; j<5; j++){
        if(board[i][j] == a.at(cnt)){
          find(i,j,cnt+1);
        }
      }
  }
  // 첫번째 이후 단어
  else{
    for(int i=0; i<8; i++){
      if(isPos>0) return;
      cx = pos[i][0] + x;
      cy = pos[i][1] + y;
      if(memo[cx][cy][cnt+1]==1) continue;
      if(cx>=0 && cy>=0&& cx<5 && cy<5 && board[cx][cy] == a.at(cnt)){
        find(cx,cy,cnt+1);
      } 
    }
  }
}

int main(){
  int test;
  cin >> test;
  while (test--){
    for(int i=0; i<5; i++)
      for(int j=0; j<5; j++)
        cin >> board[i][j];

    int words;
    cin >> words;
    while (words--){
      cin >> a;

      memset(memo, 0 , sizeof(memo));
      isPos = 0;
      find(0,0,0);

      if (isPos>0) cout << a << " YES" << endl;
      else cout << a << " NO" << endl;
    }
  }
}