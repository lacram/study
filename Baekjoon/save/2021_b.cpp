#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <set>
#define endl '\n'

using namespace std;

int n,m;
int before[30][30];
int after[30][30];
int dx[2] = {1,0};
int dy[2] = {0,1};

set<pair<int,int>> s;
bool check = false;

void put(int x, int y, int val){
  s.insert(make_pair(x,y));

  for (int i=0; i<2; i++){
    int nx = x+dx[i];
    int ny = y+dy[i];

    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
    if (before[nx][ny] != val) continue;

    put(nx,ny,val);
  }

}

void solve(){
  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++)
      if (before[i][j] != after[i][j]){
        if (!check){
          put(i,j,before[i][j]);
          check = true;
        }
        else {
          if (s.find(make_pair(i,j)) == s.end()){
            cout << "NO";
            return;
          }
        }
      }

  cout << "YES";
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  // cin >> n >> m;

  // for (int i=0; i<n; i++)
  //   for (int j=0; j<m; j++)
  //     cin >> before[i][j];
  
  // for (int i=0; i<n; i++)
  //   for (int j=0; j<m; j++)
  //     cin >> after[i][j];

  n = 30;
  m = 30;

  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++)
      before[i][j] = 1;
  
  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++)
      after[i][j] = 2;

  solve();
}