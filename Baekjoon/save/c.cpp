#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,m;
string board[3000];
string bw[3000];
string wb[3000];
bool bboard[3000][3000];

void setting(){
  string b = "";
  string w = "";
  for (int i=0; i<m; i++){
    if (i % 2 == 0) b.push_back('B');
    else b.push_back('W');
  }
  for (int i=0; i<m; i++){
    if (i % 2 == 0) w.push_back('W');
    else w.push_back('B');
  }

  for (int i=0; i<n; i++){
    if (i % 2 == 0) bw[i] = b;
    else bw[i] = w;
  }

  for (int i=0; i<n; i++){
    if (i % 2 == 0) wb[i] = w;
    else wb[i] = b;
  }

  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++)
      if (board[i][j] == bw[i][j])
        bboard[i][j] = 1;
}

bool check(int x, int y, int k){
  int flag =  bboard[x][y];
  for (int i=x; i<=x+k; i++)
    if (bboard[i][y+k] != flag)
        return false;
  for (int i=y; i<=y+k; i++)
    if (bboard[x+k][i] != flag)
        return false;
  return true;
}

long long solve(){
  long long ans = 0;
  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++){
      int k = 1;
      while (check(i,j,k) && i+k < n && j+k < m){
        ans++;
        k++;
      }
    }
  return ans + n*m;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  for (int i=0; i<n; i++)
    cin >> board[i];

  setting();

  cout << solve();
}