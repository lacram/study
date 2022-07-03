#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

int test ,n,m;
long long MAX = 2000000000;

int winrate(long long a, long long b){
  return (a*100)/b;
}

int optimize(){
  if (winrate(m,n) == winrate(m+MAX,n+MAX)) return -1;

  long long lo = 0;
  long long hi = MAX;

  while (lo + 1 < hi){
    long long mid = (lo + hi)/2;
    
    if (winrate(m,n) == winrate(m+mid,n+mid)) lo = mid;
    else hi = mid;
  }

  return hi;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> test;
  while(test--){
    cin >> n >> m;
    
    cout << optimize() << endl;
  }
}