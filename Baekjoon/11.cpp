#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <map>
#define endl '\n'

using namespace std;

int n;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  map<int,int> m;
  m[1] = 1;

  if (m.find(1) == m.end())
    cout << -2;
  cout << m.count(1);
  

}