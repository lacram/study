#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int cnt=0;
bool tf=false;
int r,c;

void solve(int x, int y, int n){
  if (n==0) return;

  if (x <= r && r < x+n/2 && y <= c && c <y+n/2){
    solve(x,y,n/2);
  }
  if (x <= r && r < x+n/2 && y+n/2 <= c){
    cnt += n*n/4;
    solve(x,y+n/2,n/2);    
  }
  if (x+n/2 <= r && y <= c && c < y+n/2){
    cnt += n*n/2;
    solve(x+n/2,y,n/2);
  }
  if (x+n/2 <= r && y+n/2 <= c) {
    cnt += n*n/4*3;
    solve(x+n/2,y+n/2,n/2);
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  int n;

  cin >> n >> r >> c;

  n = pow(2,n);

  solve(0,0,n);

  cout << cnt;
}