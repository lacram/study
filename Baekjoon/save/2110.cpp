#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

int n,c;
vector<int> v;

bool decision(int gap){

  int cnt = 0;
  int pos = 0;
  for (int i=0; i<v.size(); i++){
    if (pos <= v[i]){
      pos = v[i]+gap;
      cnt++;
    }
  }
  return cnt >= c;
}

int optimize(){
  int left = 0;
  int right = 1000000000;

  for (int i=0; i<100; i++){
    int mid = (left+right)/2;
    
    if (decision(mid)) left = mid;
    else right = mid;
  }
  
  return left;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> c;

  for (int i=0; i<n; i++){
    int a;
    cin >> a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());

  cout << optimize();
}