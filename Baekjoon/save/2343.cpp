#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,m;
int arr[100000];

bool decision(int size){
  int cnt = 1;
  int blueray = 0;

  for (int i=0; i<n; i++){
    if (size < arr[i]) return false;

    if (blueray+arr[i] <= size){
      blueray += arr[i];
    }
    else{
      blueray = arr[i];
      cnt++;
    }
  }
  return cnt <= m;
}

int solve(){
  int lo = 0;
  int hi = 1000000000;
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

  cin >> n >> m;

  for (int i=0; i<n; i++){
    cin >> arr[i];
  }

  cout << solve();
}