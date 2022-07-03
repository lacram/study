#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <map>
#define endl '\n'
#define INF 2000000000

using namespace std;

int solution(string s) {
  int minLen = s.size();

  for (int len=1; len<=s.size()/2; len++) {
    string tmp = "";

    for (int i=0; i<s.size();) {
      // 짜투리 문자열
      if (i+len > s.size()) {
        tmp += s.substr(i);
        break;
      }

      int cnt = 1;
      string str = s.substr(i,len);
      i += len;
      while (s.substr(i,len) == str) {
        cnt++;
        i += len;
      }

      if (cnt > 1) tmp += to_string(cnt);
      tmp += str;
    }

    int tmpLen = tmp.size();
    minLen = min(minLen, tmpLen);
  }

  return minLen;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution();

}