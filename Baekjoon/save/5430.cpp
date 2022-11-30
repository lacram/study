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

string getAns(string ops, string str) {
  deque<string> dec;
  bool isReversed = 0;

  string s = "";
  for (int i = 0; i<str.length();i++) {
    if (isdigit(str[i])) {
      s += str[i];
    }
    else {
      if (!s.empty()) {
        dec.push_back(s);
        s = "";
      }
    }
  }

  for (auto op : ops) {
    if (op == 'R') isReversed = !isReversed;
    else {
      if (dec.empty()) {
        return "error";
      }

      if (isReversed) dec.pop_back();
      else dec.pop_front();
    }
  }

  string ans = "";
  if (isReversed) {
    for (auto it = dec.rbegin(); it!=dec.rend(); it++) {
      ans += *it + ",";
    }
  } else {
    for (auto it = dec.begin(); it!=dec.end(); it++) {
      ans += *it + ",";
    }
  }
  if (ans[ans.size()-1] == ',') ans.pop_back();
  return "[" + ans + "]";
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    string ops;
    cin >> ops;
    int len;
    cin >> len;
    string str;
    cin >> str;
    
    cout << getAns(ops,str) << endl;
  }

}