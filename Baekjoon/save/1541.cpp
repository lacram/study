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

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  string str;
  cin >> str;

  vector<int> nums;
  vector<char> ops;

  int pos = 0;
  for (int i=0; i<str.size(); i++) {
    if (str[i] == '-' || str[i] == '+') {
      ops.push_back(str[i]);
      nums.push_back(stoi(str.substr(pos, i-pos)));
      pos = i+1;
    }
  }
  nums.push_back(stoi(str.substr(pos)));

  int ans = nums[0];
  bool isMinus = 0;
  // 마이너스가 한번이라도 나오면 그 뒤는 다 마이너스 계산 가능
  for (int i=0; i<ops.size(); i++) {
    if (ops[i] == '-' || isMinus) {
      ans -= nums[i+1];
      isMinus = 1;
    } else {
      ans += nums[i+1];
    }
  }

  cout << ans;
}