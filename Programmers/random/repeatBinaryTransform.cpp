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
1. x의 모든 0을 제거합니다.
2. x의 길이를 c라고 하면, x를 "c를 2진법으로 표현한 문자열"로 바꿉니다.
 */

int deletedZeroCount;

int deleteZeroAndGetOneCount(string s) {
  int cnt = 0;
  for (int i=0; i<s.size(); i++) {
    if (s[i] == '1')
     cnt++;
  }
  deletedZeroCount += s.size() - cnt;
  return cnt;
}

string toBinary(int cnt) {
  string str = "";
  while (cnt > 0) {
    str += to_string(cnt % 2);
    cnt /= 2;
  }
  reverse(str.begin(), str.end());
  return str;
}

vector<int> solution(string s) {
  int cnt = 0;
  while (s != "1") {
    s = toBinary(deleteZeroAndGetOneCount(s));
    cnt++;
  }
  return {cnt, deletedZeroCount};
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution("1111111");

}