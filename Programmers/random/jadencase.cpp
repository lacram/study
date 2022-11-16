#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <sstream>
#define endl '\n'
#define INF 2000000000

using namespace std;

string solution(string s) {
  string ans = "";
  ans += toupper(s[0]);

  for (int i=1; i<s.size(); i++) {
    if (s[i-1] == ' ') {
      ans += toupper(s[i]);
    } else {
      ans += tolower(s[i]);
    }
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution("        a   AAA     ");

}