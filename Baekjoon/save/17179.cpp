#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,m,len,k;
int arr[1001];

bool decision(int dis){
  int last = 0;
  int cnt = 0;

  for (int i=0; i<=m; i++){
    if (last+dis <= arr[i]){
      last = arr[i];
      cnt++;
    }
  }
  return cnt >= k+1;
}

int solve(){
  int lo = 1;
  int hi = 3999999;

  while (lo <= hi){
    int mid = (lo+hi)/2;

    if (decision(mid)) lo = mid+1;
    else hi = mid-1;
  }
  return hi;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m >> len;

  for (int i=0; i<m; i++){
    cin >> arr[i];
  }
  arr[m] = len;

  for (int i=0; i<n; i++){
    cin >> k;
    cout << solve() << endl;
  }
}