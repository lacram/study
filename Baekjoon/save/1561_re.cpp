#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,m;
int runtime[10000];

bool decision(long long time){
  long long ret = 0;

  for (int i=0; i<m; i++)
    ret += time / runtime[i] + 1;
  
  return ret >= n;
}

int solve(){
  long long lo = 0;
  long long hi = 60000000000;

  while (lo <= hi) {
    long long mid = (lo+hi)/2;
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

  cin >> n >> m;

  for (int i=0; i<m; i++){
    cin >> runtime[i];
  }

}