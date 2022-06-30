#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,k,d;
int a[10000];
int b[10000];
int c[10000];

bool decision(int num){
  long long cnt = 0;
  for (int i=0; i<k; i++){
    if (a[i] > num) continue;

    cnt += (min(b[i],num)-a[i]) / c[i] + 1;
  }
  return cnt >= d;
}

int solve(){
  int lo = 1;
  int hi = 1000000;
  
  while (lo <= hi){
    int mid = (lo+hi)/2;
    if (decision(mid)) hi = mid-1;
    else lo = mid+1;
  }

  return lo;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> k >> d;

  for (int i=0; i<k; i++){
    cin >> a[i] >> b[i] >> c[i];
  }

  cout << solve();
}