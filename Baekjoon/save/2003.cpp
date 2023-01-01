#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int arr[10000];
int n,k;

int solve(){
  int lo=0,hi=0,cnt=0;
  int ret = arr[0];
  while (hi <= n-1){
    if (ret < k) ret += arr[++hi];
    else if (ret == k) {
      cnt++;
      ret -= arr[lo++];
    }
    else ret -= arr[lo++];
  }
  
  return cnt;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> k;

  for (int i=0; i<n; i++){
    cin >> arr[i];
  }

  cout << solve();
}