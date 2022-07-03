#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
typedef long long ll;

using namespace std;

int n;
ll x;
vector<ll> arr;

int solve(){
  int lo = 0; 
  int hi = n-1;
  int ans = 0;
  int cnt = 0;

  while (hi >=0 && arr[hi] >= x){
    ans++; hi--;
  }

  while (lo <= hi){
    if (lo != hi && arr[lo]+arr[hi] >= x/2.0){
      ans++;
      lo++; hi--;
    }
    else{
      lo++;
      cnt++;
    }
  }

  return ans+cnt/3;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> x;

  arr.resize(n);

  for (int i=0; i<n; i++){
    cin >> arr[i];
  }

  sort(arr.begin(),arr.end());
  
  cout << solve();
}