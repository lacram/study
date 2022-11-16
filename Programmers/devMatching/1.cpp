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

pair<string,int> divide(string str) {
  int idx = str.size();
  for (int i=0; i<str.size(); i++) {
    if (isdigit(str[i])) {
      idx = i;
      break;
    }
  }
  
  int num = 0;
  if (idx != str.size()) num = stoi(str.substr(idx));
  return {str.substr(0,idx), num};
}

string solution(vector<string> registered_list, string new_id) {
  pair<string,int> id = divide(new_id);
  string str = id.first;
  int num = id.second;

  vector<int> v;
  bool flag = false;

  for (auto r : registered_list) {
    pair<string,int> p = divide(r);
    if (p.first == str) {
      v.push_back(p.second);
    }
    if (p.first == str && p.second == num) flag = true;
  }

  if (!flag) return new_id;

  sort(v.begin(), v.end());

  bool flag2 = false;
  for (int i=0; i<v.size(); i++) {
    if (v[i] == num) {
      num++;
      flag2 = true;
    } else {
      if (flag2) return str + to_string(num);
    }
  }
  return str + to_string(num);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution({"ace13", "ace16", "ace17", "ace15"},"ace15");

}