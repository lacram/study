#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#define endl '\n'

using namespace std;

void solve(int x, int y, int n){
  if ((x/n)%3==1 && (y/n)%3==1)
    cout << ' ';
  else{
    if (n==1)
      cout << '*';
    else solve(x,y,n/3);
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  int n;

  cin >> n;

  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++)
      solve(i,j,n);
    cout << endl;
  }
    
}