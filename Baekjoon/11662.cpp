#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[8];
double x1, x2, y3, y4;

double line(double x){
  // y = (y4 - y3) / (x2 - x1) * (x - x1) + y3
  return (y4 - y3) / (x2 - x1) * (x - x1) + y3;
}

double distance(double x, double y){
  return sqrt(pow(x,2)+pow(y,2));
}

double solve(){
  double srt = x1;
  double end = x2;

  for (int i=0; i<100; i++){
    double lo = (2*srt + end)/3;
    double hi = (srt + 2*end)/3;

    if (distance(lo, line(lo)) < distance(hi, line(hi))) end = hi;
    else srt = lo;
  }

  return distance(end,line(end));
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout << fixed;
  cout.precision(7);

  // ifstream cin;
  // cin.open("input.txt");

  for (int i=0; i<8; i++){
    cin >> arr[i];
  }

  x1 = arr[4]-arr[0];
  y3 = arr[5]-arr[1];
  x2 = arr[6]-arr[2];
  y4 = arr[7]-arr[3];

  if(x1 == x2 && y3 == y4) cout << distance(x1,y3);
  else cout << solve();
}