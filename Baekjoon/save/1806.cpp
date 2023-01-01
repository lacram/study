#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,s;
int arr[100000];

int solve(){
  int lo=0,hi=0,len=100000;
  int ret = arr[0];

  while (hi < n){
    if (ret < s) ret += arr[++hi];
    else {
      len = min(len, hi-lo+1);
      ret -= arr[lo++];
    }
  }
  if (len == 100000) return 0;
  return len;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> s;

  for (int i=0; i<n; i++){
    cin >> arr[i];
  }

  cout << solve();
}