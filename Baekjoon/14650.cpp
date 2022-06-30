#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;

long long solve(){
  if (n == 1) return 0;
  
  long long ans = 2;

  for (int i=2; i<n; i++){
    ans *= 3;
    ans %= 1000000009;
  }
  return ans;
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