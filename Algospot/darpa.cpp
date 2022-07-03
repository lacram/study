#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

int test, c, s;
vector<double> station;

bool decision(double gap){

  double now = 0, cnt=0;
  for (int i=0; i<s; i++){
    // 설치 가능
    if (now <= station[i]){
      cnt++;
      now = station[i]+gap;
    }     
  }
  return cnt >= c;
}

double optimize(){
  double left = 0;
  double right = 241;

  for (int i=0; i<100; i++){
      double mid = (left+right)/2;
    if (decision(mid)) left = mid;
    else right = mid;
  }
  return left;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout<<fixed;
  cout.precision(2);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> test;
  while(test--){
    cin >> c >> s;

    station.clear();

    for (int i=0; i<s; i++){
      double a;
      cin >> a;
      station.push_back(a);
    }

    cout << optimize() << endl;
  }
}