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

vector<vector<int>> board;

void rotate(int h, int w) {
  vector<vector<int>> tmp = board;
  
  for (int i=1; i<w; i++) tmp[0][i] = board[0][i-1];
  for (int i=1; i<h; i++) tmp[i][w-1] = board[i-1][w-1];
  for (int i=0; i<w-1; i++) tmp[h-1][i] = board[h-1][i+1];
  for (int i=0; i<h-1; i++) tmp[i][0] = board[i+1][0];

  board = tmp;
}

void shiftRow(int h) {
  for (int i=h-1; i>0; i--)
    swap(board[i],board[i-1]);
}

void print(){
  for (int i=0; i<3; i++){
    for (int j=0; j<3; j++)
      cout << board[i][j] << " ";
    cout << endl;
  }
}

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
  board = rc;
  int h = rc.size();
  int w = rc[0].size();

  for (auto op : operations) {
    if (op == "Rotate") rotate(h,w);
    if (op == "ShiftRow") shiftRow(h);
  }

  return board;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  print();
  rotate(3,3);
  print();
}