#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

int gcd, gcm;

int getGcd(int x, int y){
  if (y==0) return x;
  return getGcd(y,x%y);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cin >> gcd >> gcm;

  // A = gcd x a
  // B = gcd X b
  // gcm = gcd x a x b

  long long ab = gcm / gcd;

  int a;
  for (int x=sqrt(ab); x>0; x--){
    if (ab % x == 0 && getGcd(x, ab/x) == 1){
      a = x;
      break;
    }
  }

  cout << gcd * a << " " << gcd * (ab/a);
}