#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
int a[4000];
int b[4000];
int c[4000];
int d[4000];
int ab[16000000];
int cd[16000000];


long long solve(){
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++){
      ab[i*n+j] = a[i]+b[j];
      cd[i*n+j] = c[i]+d[j];
    }
  
  sort(ab, ab+n*n);
  sort(cd, cd+n*n);

  int lo=0, hi=n*n-1;
  long long cnt=0;

  while (lo < n*n || hi > 0)
  {
    int ret = ab[lo] + cd[hi];
    if (ret > 0) hi--;
    else if (ret < 0) lo++;
    else {
      long long a=1,b=1;
      while (ab[lo+1] == ab[lo] && lo+1 < n*n) {
        a++;
        lo++;
      }
      while (cd[hi-1] == cd[hi] && hi-1 >= 0) {
        b++;
        hi--;
      }
      cnt += a*b;
      lo++;
      hi--;
    }
  }
  
  return cnt;
}


int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }

  cout << solve();
}