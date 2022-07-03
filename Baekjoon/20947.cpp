#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
string board[2000];
bool row[2000];
bool col[2000];

bool check(int x, int y){
  bool flag = false;

  for (int i=x; i<n; i++){
    if (board[i][y] == 'O'){
      row[y] = 0;
      return false;
    }
    if (board[i][y] == 'X'){
      flag = true;
      break;
    }
  }
  for (int i=y; i<n; i++){

    if (board[x][i] == 'O'){
      col[x] = 0;
      return false;
    }
    if (board[x][i] == 'X'){
      flag = true;
      break;
    }
  }
  for (int i=x; i>=0; i--){

    if (board[i][y] == 'O'){
      row[y] = 0;
      return false;
    }
    if (board[i][y] == 'X'){
      flag = true;
      break;
    }
  }
  for (int i=y; i>=0; i--){

    if (board[x][i] == 'O'){
      col[x] = 0;
      return false;
    }
    if (board[x][i] == 'X'){
      flag = true;
      break;
    }
  }
  if (!flag) return false;
  return true;
}

void solve(){
  memset(row, 1, sizeof(row));
  memset(col, 1, sizeof(col));

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++){

      if (board[i][j] == '.'){
        if (check(i,j)) 
          board[i][j] = 'B';
      }
    }
  
  for (int i=0; i<n; i++){
    cout << board[i] << endl;
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++)
    cin >> board[i];
  
  solve();
}