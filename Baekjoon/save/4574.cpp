#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
int board[9][9];
int used[10][10];
bool fin = false;

bool checkRow(int r, int num){
  for (int i=0; i<9; i++){
    if (board[r][i] == num) 
      return false;
  }
  return true;
}

bool checkCol(int c, int num){
  for (int i=0; i<9; i++){
    if (board[i][c] == num) 
      return false;
  }
  return true;
}

bool checkBox(int r, int c, int num){
  int x = r/3*3;
  int y = c/3*3;
  for (int i=0; i<3; i++)
    for (int j=0; j<3; j++){
      if (board[x+i][y+j] == num) 
        return false;
    }
  return true;
}

bool check(int r, int c, int num){
  return checkBox(r,c,num) && checkCol(c,num) && checkRow(r,num);
}

void solve(){
  if (fin) return;

  int x=-1,y;
  for (int i=0; i<9; i++){
    for (int j=0; j<9; j++){
      if (!board[i][j]){
        x = i;
        y = j;
        break;
      }
      if (x != -1) break;
    }
    if (x != -1) break;
  }

  if (x == -1) {
    fin = true;
    for (int i=0; i<9; i++){
      for (int j=0; j<9; j++)
        cout << board[i][j];
      cout << endl;
    }
    return;
  }

  for (int i=1; i<=8; i++)
    for (int j=i+1; j<=9; j++){ 
      if (!used[i][j]){
        used[i][j] = 1;
        used[j][i] = 1;
        // 가로
        if (y+1 < 9 && !board[x][y+1]){
          if (check(x,y,i) && check(x,y+1,j)){
            board[x][y] = i;
            board[x][y+1] = j;
            solve();
            board[x][y] = 0;
            board[x][y+1] = 0;
          }
          if (check(x,y,j) && check(x,y+1,i)){
            board[x][y] = j;
            board[x][y+1] = i;
            solve();
            board[x][y] = 0;
            board[x][y+1] = 0;
          } 
        }
        // 세로
        if (x+1 < 9 && !board[x+1][y]){
          if (check(x,y,i) && check(x+1,y,j)){
            board[x][y] = i;
            board[x+1][y] = j;
            solve();
            board[x][y] = 0;
            board[x+1][y] = 0;
          }
          if (check(x,y,j) && check(x+1,y,i)){
            board[x][y] = j;
            board[x+1][y] = i;
            solve();
            board[x][y] = 0;
            board[x+1][y] = 0;
          } 
        }
        used[i][j] = 0;
        used[j][i] = 0;
      }
    }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  int test = 1;
  while(1){
    cin >> n;
    if (n == 0) break;

    for (int i=0; i<n; i++){
      int num[2];
      for (int j=0; j<2; j++){
        string str;
        cin >> num[j];
        cin >> str;

        int x = str[0]-'A';
        int y = str[1]-'1';

        board[x][y] = num[j];
      }
      used[num[0]][num[1]] = 1;
      used[num[1]][num[0]] = 1;
    }

    for (int j=1; j<=9; j++){
      string str;
      cin >> str;
      int x = str[0]-'A';
      int y = str[1]-'1';

      board[x][y] = j;
    }
    

    cout << "Puzzle " << test << endl;
    solve();

    test++;
    fin = false;
    memset(board, 0, sizeof(board));
    memset(used, 0, sizeof(used));
  }
}