#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

int test, n, k;
int des[5000];
int start[5000];
int interval[5000];

bool decision(int pos){
  int cnt = 0;

  for (int i=0; i<n; i++){
    if (pos >= start[i]) 
      cnt += (min(pos-start[i],des[i]-start[i])) / interval[i] + 1;
  }

  return cnt >= k;
}

int optimize(){
  int left = 0;
  int right = 8030000;

  for (int i=0; i<100; i++){
    int mid = (left+right)/2;

    if (decision(mid)) right = mid;
    else left = mid;
  }
  return right;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> test;
  while(test--){
    cin >> n >> k;

    for (int i=0; i<n; i++){
      cin >> des[i];
      int a;
      cin >> a;
      start[i] = des[i]-a;
      cin >> interval[i];
    }

    cout << optimize() << endl;
  }
}