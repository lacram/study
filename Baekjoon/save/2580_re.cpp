#include <iostream>
#include <fstream>
#define endl '\n'

using namespace std;

int board[9][9];
bool findAns = false;

bool checkRow(int x, int num){
  for (int i=0; i<9; i++)
    if (board[x][i] == num)
      return false;
  return true;
}

bool checkCol(int x, int num){
  for (int i=0; i<9; i++)
    if (board[i][x] == num)
      return false;
  return true;
}

bool checkBox(int x, int y, int num){
  int nx = x/3*3;
  int ny = y/3*3;
  for (int i=nx; i<nx+3; i++)
    for (int j=ny; j<ny+3; j++)
      if (board[i][j] == num)
        return false;
  return true;
}

void print(){
  for (int i=0; i<9; i++){
    for (int j=0; j<9; j++)
      cout << board[i][j] << " ";
    cout << endl;
  }
}

void solve(){
  if (findAns) return;

  int x=-1, y;

  for (int i=0; i<9; i++){
    for (int j=0; j<9; j++)
      if (board[i][j] == 0){
        x = i;
        y = j;
        break;
      }
    if (x != -1)
      break;
  }

  if (x == -1){
    print();
    findAns = true;
    return;
  }
  
  for (int i=1; i<=9; i++)
    if (checkBox(x,y,i) && checkCol(y,i) && checkRow(x,i)){
      board[x][y] = i;
      solve();
      board[x][y] = 0;
    }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  int n;
  cin >> n;

  for (int t=1; t<=n; t++){

    for (int i=0; i<9; i++)
      for (int j=0; j<9; j++)
        cin >> board[i][j];

    cout << "sudoku " <<  t << endl; 
    findAns = false;
    solve();
  }

}