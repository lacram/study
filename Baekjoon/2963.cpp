#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

string str;

string bigNumberAdd(string a, string b) {
  long long carry = 0;
  string result = "";

  // a : 124524244247338 7 b: 12452424424733 8  a+b = 15 -> result : 5123213
  while (!a.empty() || !b.empty() || carry) {
    if (!a.empty()) {
      carry += a.back() - '0';
      a.pop_back();
    }

    if (!b.empty()) {
      carry += b.back() - '0';
      b.pop_back();
    }

    result += ((carry % 10) + '0');
    carry /= 10;
  }

  reverse(result.begin(), result.end());
  return result;
}

string bigNumberAdd(string a, int b) {
  long long carry = 0;
  string result = "";

  while (!a.empty() || carry) {
    if (!a.empty()) {
      carry += a.back() - '0';
      a.pop_back();
    }

    carry *= b;

    result += ((carry % 10) + '0');
    carry /= 10;
  }

  reverse(result.begin(), result.end());
  return result;
}

string bigNumberMul(string a, int b) {
  long long carry = 0;
  long long num = 0;
  string result = "";

  while (!a.empty() || carry) {
    if (!a.empty()) {
      num = a.back() - '0';
      a.pop_back();
      num *= b;
    }
    else num = 0;

    result += ((num % 10)+carry + '0');
    carry = num / 10;
  }

  reverse(result.begin(), result.end());
  return result;
}

string solve(){
  string ret = "1";
  string cnt = "1";

  for (int i=0; i<str.length(); i++){
  
    if (str[i] == 'L') {
      ret = bigNumberAdd(ret,ret);
    }
    if (str[i] == 'R') {
      ret = bigNumberAdd(ret,ret);
      ret = bigNumberAdd(ret,cnt);
    }
    if (str[i] == 'P') {
      continue;
    } 
    if (str[i] == '*'){
      ret = bigNumberMul(ret,5);
      ret = bigNumberAdd(ret,cnt);

      cnt = bigNumberMul(cnt,3);    
    }
  } 
  
  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> str;

  cout << solve();

}