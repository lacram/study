#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,m;
int board[3001][3001];
int dpW[3001][3001];
int dpB[3001][3001];

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  for (int i=1; i<=n; i++){
    string s;
    cin >> s;
    for (int j=1; j<=m; j++){
      if (s[j-1] == 'B') board[i][j] = 1;
      else board[i][j] = 0;

      if ((i+j) % 2 == 1) {
        if (board[i][j]) board[i][j] = 0;
        else board[i][j] = 1;
      }
    }
  }

  long long ans = 0;

  for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++){
      if (board[i][j] == 1){
        dpW[i][j] = min(min(dpW[i-1][j-1],dpW[i][j-1]),dpW[i-1][j])+1;
        ans += dpW[i][j];
      }
      else{
        dpB[i][j] = min(min(dpB[i-1][j-1],dpB[i][j-1]),dpB[i-1][j])+1;
        ans += dpB[i][j];
      }
    }

  cout << ans;
}