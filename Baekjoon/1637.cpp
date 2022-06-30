#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,ans;
long long a[20000];
long long b[20000];
long long c[20000];

long long decision(long long num){
  long long cnt = 0;

  for (int i=0; i<n; i++){
    if (num < a[i]) continue;

    cnt += (min(num, c[i]) - a[i]) / b[i] + 1;
  }

  return cnt;
}

int solve(){
  long long lo = 1;
  long long hi = 2147483647;

  while (lo <= hi){
    long long mid = (lo+hi)/2;

    if (decision(mid) % 2 == 1) hi = mid-1;
    else lo = mid+1;
  }
  if (lo == 2147483648) return -1;

  return lo;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    cin >> a[i] >> c[i] >> b[i];
  }

  int num = solve();

  if (num != -1) cout << num << " " << decision(num) - decision(num-1);
  else cout << "NOTHING";
}