#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int test;
bool notprime[2000001];
vector<int> prime;

void eratos(){

  for (int i=2; i<=2000000; i++){
    if (notprime[i]) continue;

    prime.push_back(i);
    for (int j=i*2; j<=2000000; j+=i)
      notprime[j] = 1;
  }
}

bool solve(long long num){
  if (num == 2 || num == 3) return false;
  else if (num % 2 == 0) return true;
  else {
    num -= 2;
    if (num <= 2000000) return !notprime[num];

    for (auto p : prime)
      if (num % p == 0){
        return false; 
      }

    return true;
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> test;

  eratos();

  while (test--){
    long long a,b;
    cin >> a >> b;

    if (solve(a+b)) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}