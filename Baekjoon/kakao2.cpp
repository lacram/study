#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

vector<int> number;
vector<int> prime;
bool isprime[1200001];

void getNum(int n, int k){
  while (n != 0){
    number.push_back(n % k);
    n /= k;
  }
  reverse(number.begin(),number.end());
}

void eratos(){
  memset(isprime,1,sizeof(isprime));

  // 최대 1212210202001 -> 1200000까지만 구하면 됨
  for (int i=2; i<=1200000; i++)
    if (isprime[i]){
      prime.push_back(i);
      for (long long j=(long long)i*i; j<=1200000; j+=i)
        isprime[j] = 0;
    }
}

int solve(int n, int k){
  eratos();
  getNum(n,k);

  int ans = 0;
  int i = 0;

  while (i < number.size()){
    vector<int> num;
    // P0처럼 소수 오른쪽에만 0이 있고 왼쪽에는 아무것도 없는 경우

    while (i < number.size() && number[i] != 0){
      num.push_back(number[i]);
      i++;
    }

    int result = 0;
    for (auto d : num) {
      result = result * 10 + d;
    }

    if (result <= 1) {
      i++;
      continue;
    }

    bool flag = true;
    for (auto p : prime){
      if (p > sqrt(result)) break;
      if (result == 1 || result % p == 0) {
        flag = false;
        break;
      }
    }
    if (flag) {
      ans++;
    }
    i++;
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solve(3,4);
}