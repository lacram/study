#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

int h,w,pos;

int board[16][16];

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  ifstream cin;
  cin.open("input.txt");

  cin >> h >> w >> pos;
  
  for (int i=0; i<=h; i++)
    for (int j=0; j<=h; j++)
      board[i][j] = 0;
}