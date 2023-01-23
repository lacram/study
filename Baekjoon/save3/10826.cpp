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

int n;
string dp[10001];

// a가 더 긺
string operator+(string a, string b) {
  string ans = "";
  if (a.size() > b.size()) b.insert(0,"0");

  int carry = 0;
  for (int i=a.size()-1; i>=0; i--) {
    int tmp = a[i] - '0' + b[i] - '0' + carry;
    ans.push_back((tmp%10)+'0');
    carry = 0;
    if (tmp >= 10) carry = 1;
  }
  if (carry) ans.push_back('1');

  reverse(ans.begin(), ans.end());

  return ans;
}

string fibonacci(int k) {
  if (k == 0) return "0";
  if (k == 1) return "1";

  string& ret = dp[k];
  if (ret != "") return ret;
  return ret = fibonacci(k-1) + fibonacci(k-2);
}

string solution() {
  return fibonacci(n);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  cout << solution();
}