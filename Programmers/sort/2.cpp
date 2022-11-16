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

// 한 숫자가 다른 숫자에 포함될 경우 고려
bool compare(string s1, string s2) {
  return s1+s2 > s2+s1;
}

string solution(vector<int> numbers) {

  vector<string> v;
  for (auto number : numbers) {
    v.push_back(to_string(number));
  }

  sort(v.begin(), v.end(), compare);

  string ans = "";
  for (auto a : v) {
    ans += a;
  }
  
  if (ans[0] == '0') return "0";
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution({45, 454});

}