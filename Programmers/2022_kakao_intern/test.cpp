#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#define endl '\n'
#define INF 2000000000

using namespace std;

int board[3][3] ={
    {1,2,3},
    {4,5,6},
    {7,8,9}
};

void rotate() {
  int tmp = board[0][0];
  board[0][0] = board[1][0];
  board[1][0] = board[2][0];
  board[2][0] = board[2][1];
  board[2][1] = board[2][2];
  board[2][2] = board[1][2];
  board[1][2] = board[0][2];
  board[0][2] = board[0][1];
  board[0][1] = tmp;
}

void shift() {
  swap(board[0], board[1]);
  swap(board[0], board[2]);
}

void print(){
  for (int i=0; i<3; i++){
    for (int j=0; j<3; j++)
      cout << board[i][j] << " ";
    cout << endl;
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  for (int i=0; i<3; i++) rotate();
  for (int i=0; i<1; i++) shift();
  for (int i=0; i<5; i++) rotate();
  for (int i=0; i<2; i++) shift();


  print();
}