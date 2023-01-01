#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

int n, budget;
int arr[10000];

bool decision(int limit){
  int total = 0;

  for (int i=0; i<n; i++){
    if (arr[i] > limit) total += limit;
    else total += arr[i];
  }

  return total <= budget;
}

int solve(){
  int lo = 1;
  int hi = 100000;

  while (lo <= hi){
    int mid = (lo+hi)/2;
    if (decision(mid)) lo = mid+1;
    else hi = mid-1;
  }
  
  if (hi == 100000) return arr[n-1];
  return hi;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    cin >> arr[i];
  }

  cin >> budget;
  
  sort(arr, arr+n);

  cout << solve();
}