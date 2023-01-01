#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
int dist[100000];
int people[100000];
long long M = 100000000000000; 

bool decision(int pos){
  long long ret = 0;
  for (int i=0; i<n; i++){
    ret += abs(dist[i]-pos)*people[i];
  }

  if (ret < M) {
    M = ret;
    return true;
  }
  else return false;
}

int solve(){
  int lo = -1000000000;
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

  ifstream cin;
  cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    cin >> dist[i] >> people[i];
  }

  cout << solve();
}