#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#define endl '\n'
#define INF 2000000000

using namespace std;

int solution(string s) {

  int ans = 0;
  for (int i=0; i<s.size(); i++) {
    // 홀수길이 펠린드롬
    int lo = i;
    int hi = i;
    while (lo >= 0 && hi < s.size() && s[lo] == s[hi]) {
      lo--; hi++;
    }
    ans = max(ans, hi-lo-1);
  }

  for (int i=0; i<s.size()-1; i++) {
    // 짝수길이 펠린드롬
    int lo = i;
    int hi = i+1;
    while (lo >= 0 && hi < s.size() && s[lo] == s[hi]) {
      lo--; hi++;
    }
    ans = max(ans, hi-lo-1);
  }

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}