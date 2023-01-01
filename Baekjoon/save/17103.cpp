#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int test;
int notprime[1000001];
vector<int> prime;

void eratos(){
  for (int i=2; i<=1000; i++){
    if (!notprime[i]){
      for (int j=i*i; j<=1000000; j+=i)
        notprime[j] = 1;
    }
  }

  for (int i=2; i<=1000000; i++)
    if (!notprime[i])
      prime.push_back(i);
}

int solve(int num){
  int cnt = 0;
  for (int i=0; i<prime.size(); i++){
    if (prime[i] > num/2) return cnt;

    if (!notprime[num-prime[i]])
      cnt++;
  }

  return -1;
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
    int n;
    cin >> n;
    
    cout << solve(n) << endl;
  }

}