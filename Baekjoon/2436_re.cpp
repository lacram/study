#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int getGcd(int x, int y){
  if (y == 0) return x;
  return getGcd(y, x%y);
}

int solve(int ab){
  int sqrtab = sqrt(ab);

  for (int a=sqrtab; a>0; a--)
    if (ab % a == 0 && getGcd(a, ab/a) == 1)
      return a;
  return -1;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  int gcd, gcm;

  cin >> gcd >> gcm;

  // A = gcd x a
  // B = gcd x b
  // gcm = gcd x a x b
  // A x B = gcd x gcm

  int ab = gcm / gcd;

  int a = solve(ab);

  cout << a * gcd << " " << ab/a * gcd;
}