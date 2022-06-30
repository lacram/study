#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;
  
  long long ans = 1;

  int lo=n,hi;

  for (int i=2; i*i<=n; i++){
    lo = n/i;
    hi = n/(i-1);
    if (n%i != 0) lo++;
    if (n%(i-1) != 0) hi++;

    ans += (hi - lo) * i;
  }
  
  for (int i=1; i<lo; i++){
    if (n%i != 0) ans++;
    ans += n/i;
  }
  
  cout << ans;
}