#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

long long n;
bool isprime[1000001];
vector<int> prime; 
vector<long long> factor;

void eratos(){
  memset(isprime, 1, sizeof(isprime));

  for (int i=2; i<=sqrt(n); i++){
    if (isprime[i]){
      prime.push_back(i);
      for (long long j=(long long)i*i; j<=n,j<=1000000; j+=i)
        isprime[j] = 0;
    }
  }
}

// 소인수분해
void getFactor(){
  eratos();

  for (auto p : prime){
    while (n % p == 0){
      n /= p;
      factor.push_back(p);
    }
  }
  if (n > 1) factor.push_back(n);
}

// 소인수가 4개 이하면 -1
// 4개 이상이면 최소인 소인수끼리 곱해야 사전순으로 앞선 수열이 됨.
void solve(){
  int size = factor.size();
  if (size < 2) {
    cout << -1;
    return;
  }
  else {
    int idx = 0;
    while (size >= 4){
      cout << factor[idx] * factor[idx+1] << " ";
      idx += 2;
      size -= 2;
    }
    long long ans = 1;
    for (int i=idx; i<factor.size(); i++)
      ans *= factor[i];
    cout << ans;
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  getFactor();

  solve();
}