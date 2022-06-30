#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

int n, budget;
vector<int> v;

bool decision(int limit){
  long long ret=0;

  for (int i=0; i<n; i++){
    if (v[i] < limit) ret += v[i];
    else {
      ret += limit*(n-i);
      break;
    }
  }

  return ret <= budget;
}

int optimize(){
  int lo = 0;
  int hi = 100001;

  for (int i=0; i<100; i++){
    int mid = (lo+hi)/2;

    if (decision(mid)) lo = mid;
    else hi = mid;
  }
  if (lo == 100000) return v.back();
  return lo;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    int a;
    cin >> a;
    v.push_back(a);
  }
  cin >> budget;

  sort(v.begin(), v.end());

  cout << optimize();
}