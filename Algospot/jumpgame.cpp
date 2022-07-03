#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

int board[100][100];
int memo[100][100];
int n;
bool canGo;

void solve(int x, int y){
  if (x==n-1 && y==n-1) {
    canGo = true;
    return;
  }

  if(memo[x][y] == 0) return;

  int m = board[x][y];
  if (x+m < n) {
    solve(x+m , y);
    memo[x+m][y] = 0;
  }
  if (y+m < n) {
    solve(x, y+m);
    memo[x][y+m] = 0;
  }
}

int main(){
  // ifstream cin;
  // cin.open("test.txt");
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int test;

  cin >> test;
  while (test--){
    cin >> n;

    canGo = false;
    memset(memo, 1, sizeof(memo));

    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        cin >> board[i][j];
    
    solve(0,0);

    if (canGo) cout << "YES" << '\n';
    else cout << "NO" << '\n';
  }
}