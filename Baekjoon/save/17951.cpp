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

bool decision(int score){
  int cnt = 1;
  int total = 0;
  int ret = 100000;

  for (int i=0; i<n; i++){
    if (arr[i]+total < score){
      total += arr[i];
    }
    else{
      ret = min(ret, total+arr[i]);
      cnt++;
      total = 0;
    }
  }
  if (total != 0)
    ret = min(ret, total);

  if (cnt > m) return true;
  else if (cnt < m) return false;
  else return ret >= score;
}

int solve(){
  int lo = 1;
  int hi = 2000000;

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

  cin >> n >> m;

  for (int i=0; i<n; i++){
    cin >> arr[i];
  }

  cout << solve();
}