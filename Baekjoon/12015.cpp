#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <set>

using namespace std;

int n;

int solve(){
  int a;
  cin >> a;
  vector<int> s = {a};
  
  for (int i=1; i<n; i++){
    cin >> a;

    if (s.back() >= a) {
      auto it = lower_bound(s.begin(), s.end(), a);
      *it = a;
    }   
    else{
      s.push_back(a);
    }
  }
  return s.size();
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  cout << solve();
}