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
조건 1. n의 다음 큰 숫자는 n보다 큰 자연수 입니다.
조건 2. n의 다음 큰 숫자와 n은 2진수로 변환했을 때 1의 갯수가 같습니다.
 */

string NumberToBinary(int n) {
  string s = "";
  while (n) {
    s += to_string(n%2);
    n /= 2;
  }
  reverse(s.begin(), s.end());
  return s;
}

int getOneCount(string s) {
  int cnt = 0;
  for (int i=0; i<s.size(); i++) {
    if (s[i] == '1') 
      cnt++;
  }
  return cnt;
}

bool compareOneCount(int n, int m) {
  return getOneCount(NumberToBinary(n)) == getOneCount(NumberToBinary(m));
}

int solution(int n) {
  for (int i=n+1; i<=1000000; i++) {
    if (compareOneCount(n,i)) {
      return i;
    }
  }
  return -1;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}