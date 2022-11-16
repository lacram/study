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

string toString(long long number) {
  string str = "";
  while (number) {
    str.push_back((number % 2) + '0');
    number /= 2;
  }
  // str의 크기가 2의 거듭 제곱-1이 되어야함
  while (str.size() & str.size()+1) {
    str.push_back('0');
  }
  reverse(str.begin(), str.end());
  
  return str;
}

bool getAns(string number) {
  int n = number.size();
  bool tf = 1;

  if (n <= 1) return true;

  if (number[n/2] == '0') {
    for (int i=0; i<n/2; i++) {
      if (number[i] == '1') return false;
    }
    for (int i=n/2+1; i<n; i++) {
      if (number[i] == '1') return false;
    }
  } else {
    tf &= getAns(number.substr(0,n/2));
    tf &= getAns(number.substr(n/2+1));
  }
  return tf;
}

vector<int> solution(vector<long long> numbers) {
  vector<int> ans = {};
  for (auto number : numbers) {
    string num = toString(number);
    ans.push_back(getAns(num));
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution({7,5});


}