#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#define endl '\n'
#define INF 2000000000

using namespace std;

int n;
int arr[101];
int primeNumber[101];
vector<int> primeNumbers;

/* 
소인수분해 set에 저장
map으로 최대 공통소수 개수 찾기 

 */

void getPrimeNumbers() {
  for (int i=2; i<=100; i++) 
    primeNumber[i] = i;

  for (int i=2; i<=sqrt(100); i++) {
    if (primeNumber[i] == 0) continue;
    
    // i-1까지는 위의 반복문을 통해 검사됨
    for (int j=i*i; j<=100; j+=i) {
      primeNumber[j] = 0;
    }
  }
  for (int i=2; i<=100; i++) {
    if (primeNumber[i]) primeNumbers.push_back(i);
  }
}

set<int> getPrimeCount(int n) {
  set<int> s;
  for (auto prime : primeNumbers) {
    while (n % prime == 0) {
      n /= prime;
      s.insert(prime);
    }
    if (n == 1) return s;
  }
}

int getAns() {
  map<int,int> m;
  for (int i=0; i<n; i++) {
    set<int> s = getPrimeCount(arr[i]);
    for (auto num : s) {
      m[num]++;
    }
  }

  int ans = 0;
  for (auto [key,value] : m) {
    ans = max(ans, value);
  }
  return ans;
}

int solution() {
  getPrimeNumbers();
  
  return getAns();
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    cin >> arr[i];
  }

  cout << solution();
}