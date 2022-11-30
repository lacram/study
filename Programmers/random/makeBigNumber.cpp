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

string solution(string number, int k) {
  stack<int> s;

  for (auto n : number) {
    while (!s.empty() && k && s.top() < n) {
      s.pop();
      k--;
    }
    s.push(n);
  }

  while (k--) {
    s.pop();
  }

  string ans = "";
  while (!s.empty()) {
    ans.push_back(s.top());
    s.pop();
  }
  reverse(ans.begin(), ans.end());

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution("9090", 2);

}