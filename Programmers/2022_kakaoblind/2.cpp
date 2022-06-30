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
#define endl '\n'
#define INF 2000000000

using namespace std;

/* 
1. 주어진 수를 해당 진법으로 변환
2. 0기준으로 분리
3. 소수인지 판별
 */

bool isPrime(long long n) { 
  if(n < 2) return false;
      
  for(int i=2; i<=sqrt(n); ++i) {
      if(n % i == 0) return false;
  }
  
  return true;
}

string getNum(int n, int k) {
  string num = "";

  while (n > 0) {
    num.push_back((n % k)+'0');
    n /= k;
  }
  reverse(num.begin(), num.end());

  return num;
}

int solution(int n, int k) {
  string num = getNum(n,k);

  vector<long long> numbers;
  int pos = 0;
  for (int i=0; i<num.size(); i++) {
    if (num[i] == '0') {
      numbers.push_back(stoll(num.substr(pos,i-pos)));
      while(i<num.size() && num[i] == '0') i++;
      pos = i;
    }
  }
  if (pos < num.size()) numbers.push_back(stoll(num.substr(pos)));
  
  int cnt = 0;
  for (auto number : numbers) {
    if (isPrime(number)) cnt++;
  }

  return cnt;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

  cout << solution(524287,2);

}