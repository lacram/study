#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

int test, m;
double n,p;

bool decision(double cost){
  double money = n;

  for (int i=0; i<m; i++){
    money += money * (p/1200);
    money -= cost;
  }

  return money <= 0;
}

double optimize(){
  double lo = 0;
  double hi = 200000000;

  for (int i=0; i<100; i++){
    double mid = (lo+hi)/2;

    if (decision(mid)) hi = mid;
    else lo = mid;
  }

  return hi;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout << fixed;
  cout.precision(8);
  
  // ifstream cin;
  // cin.open("input.txt");

  cin >> test;
  while(test--){
    cin >> n >> m >> p;

    cout << optimize() << endl;
  }
}