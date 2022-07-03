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

vector<string> combi[11];

// str1안에 str2가 있는지 판별
bool find(string str1, string str2) {
  for (auto s2 : str2) {
    if (str1.find(s2) == string::npos) return false;
  }
  return true;
}

void makeCombination(string str, string tmp, int now, int depth) {
  if (tmp.size() == depth) {
    sort(tmp.begin(), tmp.end());
    combi[depth].push_back(tmp);
    return;
  }

  for (int i=now; i<str.size(); i++) {
    makeCombination(str, tmp+str[i], i+1, depth);
  }
}

vector<string> solution(vector<string> orders, vector<int> course) {
  map<string,int> m;

  for (auto order : orders) {
    for (auto c : course)
      if (order.size() >= c) makeCombination(order, "", 0, c);
  }

  for (auto c : course) {
    for (auto com : combi[c]){
      int cnt = 0;
      for (auto order : orders) {
        if (find(order,com)) cnt++;
      }
      if (cnt >= 2) {
        m[com] = cnt;
      }
    }
  }

  vector<int> max(11,0);
  vector<string> ans;

  for (auto &item : m) {
    string str = item.first;
    int cnt = item.second;
    int n = str.size();
    if (max[n] < cnt) max[n] = cnt;
  }

  for (auto &item : m) {
    string str = item.first;
    int cnt = item.second;
    int n = str.size();
    
    if (max[n] == cnt) ans.push_back(str);
  }

  sort(ans.begin(), ans.end());

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  vector<string> v = solution({"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"} ,      {2,3,5});

  for (auto a : v) cout << a << endl;

}