#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
int notprime[4000000];
vector<int> prime;
vector<long long> psum;

void eratos(){
  for (int i=2; i<sqrt(4000000)+1; i++){
    if (notprime[i]) continue;
    for (int j=i*i; j<4000000; j+=i){
      notprime[j] = 1;
    }
  }
  
  for (int i=2; i<4000000; i++)
    if (!notprime[i]) 
      prime.push_back(i);
}

int solve(){
  int idx = lower_bound(prime.begin(), prime.end(), n)-prime.begin();

  int lo=0,hi=0,cnt=0;
  int ret = prime[0];
  while (hi <= idx){
    if (ret < n) ret += prime[++hi];
    else if (ret == n) {
      cnt++;
      ret -= prime[lo++];
    }
    else ret -= prime[lo++];
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

  eratos();

  cout << solve();
}