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

vector<string> solution(vector<string> record) {
  vector<string> ans;
  map<string, vector<int>> m;
  map<string, string> mapping;
  int idx = 0;

  for (auto r : record) {
    int pos = 0;
    vector<string> words;
    while ((pos = r.find(" ")) != string::npos){
      words.push_back(r.substr(0, pos));
      r.erase(0, pos + 1);
    }
    words.push_back(r);

    string op = words[0];
    string id = words[1];
    string name;
    if (words.size() == 2) name = mapping[id];
    else name = words[2];

    if (op == "Enter"){
      ans.push_back(name + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù");
      for (auto a : m[id]) {
        ans[a] = ans[a].replace(0,mapping[id].size(), name);
      }
      mapping[id] = name;
      m[id].push_back(idx++);
    }
    if (op == "Leave") {
      ans.push_back(name + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
      m[id].push_back(idx++);
    }
    if (op == "Change") {
      for (auto a : m[id]) {
        ans[a] = ans[a].replace(0,mapping[id].size(), name);
      }
      mapping[id] = name;
    }
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;

  vector<string> v =  solution({"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"});

  for (auto a : v)
    cout << a << endl;
}