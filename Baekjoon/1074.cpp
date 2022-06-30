#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int ans=0;

void solve(int x, int y, int n){
  if (n==1) return;

  int a = x/(n/2);
  int b = y/(n/2);

  ans += a*pow(n,2)/2 + b*pow(n,2)/4;
  
  x = x-n/2 >= 0 ? x-n/2 : x;
  y = y-n/2 >= 0 ? y-n/2 : y;

  solve(x, y, n/2);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  int n,r,c;

  cin >> n >> r >> c;
  
  solve(r,c,pow(2,n));

  cout << ans;
}