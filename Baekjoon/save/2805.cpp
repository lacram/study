#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

int n,m;
vector<int> v;

bool decision(int height){
  long long cnt=0;

  for (int i=0; i<v.size(); i++)
    cnt += v[i] - height > 0 ? v[i]-height : 0;
  
  return cnt >= m;
}

int optimize(){
  int left = 0;
  int right = 1000000000;

  for (int i=0; i<100; i++){
    int mid = (left+right)/2;

    if(decision(mid)) left = mid;
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

  cin >> n >> m;

  for (int i=0; i<n; i++){
    int a;
    cin >> a;
    v.push_back(a);
  }
  
  cout << optimize();
}