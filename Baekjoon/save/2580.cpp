#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

int board[9][9];
bool finish = false;

void checkCol(int x, int y, int *used){
  for (int i=0; i<9; i++)
    used[board[i][y]]++;
}
void checkRow(int x, int y, int *used){
  for (int i=0; i<9; i++)
    used[board[x][i]]++;
}
void checkBox(int x, int y, int *used){
  int nx = x/3*3;
  int ny = y/3*3;
  for (int i=nx; i<nx+3; i++)
    for (int j=ny; j<ny+3; j++)
      used[board[i][j]]++;
}

void print(){
  for (int i=0; i<9; i++){
    for (int j=0; j<9; j++)
      cout <<  board[i][j] << " ";
    cout << endl;
  }
}

void solve(){
  if (finish) return;

  int x=-1,y;
  for (int i=0; i<9; i++){
    for (int j=0; j<9; j++)
      if (!board[i][j]){
        x = i;
        y = j;
        break;
      }
    if (x != -1) break;
  }
  if (x == -1) {
    finish = true;
    print();
    return;
  }
  int used[10] = {0};

  checkBox(x,y,used);
  checkCol(x,y,used);
  checkRow(x,y,used);
  for (int k=1; k<10; k++){
    if (!used[k]){
      board[x][y] = k;
      solve();
      board[x][y] = 0;
    }
  }

}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  for (int i=0; i<9; i++)
    for (int j=0; j<9; j++)
      cin >> board[i][j];

  solve();

}