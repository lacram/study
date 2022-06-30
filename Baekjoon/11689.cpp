#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

vector<long long> factor;

void getFactor(long long num){
  long long n = num;
  for (int i=2; i<=(int)sqrt(num); i++){
    if (n % i != 0) continue;

    while (n % i == 0) {
      n /= i;
    }
    factor.push_back(i);
  }
  if (n > 1) factor.push_back(n);
}

long long solve(long long n){
  long long ans = n;
  for (auto f : factor){
    ans *= 1 - 1 / (double)f;
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  long long n;
  cin >> n;

  getFactor(n);

  cout << solve(n);
}