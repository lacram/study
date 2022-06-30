#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,k;

bool decision(int num){
  int cnt = 0;
  for (int i=1; i<=n; i++)
    cnt += min(n, num/i);
  
  return cnt >= k;
}

int solve(){
  int lo = 1;
  int hi = 1000000000;

  while(lo <= hi){
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

  cin >> n >> k;

  cout << solve();
}