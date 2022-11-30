#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
bool notprime[100000001];
vector<int> prime;

void eratos(){
  for (int i=2; i<=sqrt(n); i++){
    if (notprime[i]) continue;

    prime.push_back(i);
    for (int j=i*i; j<=n; j+=i)
      notprime[j] = 1;
  }

  for (int i=(int)sqrt(n)+1; i<=n; i++)
    if (!notprime[i])
      prime.push_back(i);
}

long long solve(){
  long long ans = 1;
  long long div = pow(2,32);

  for (auto p : prime){
    long long factor = p;

    while (factor <= n){
      ans *= p;
      ans %= div;
      factor *= p;
    }
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

  eratos();

  cout << solve();
}