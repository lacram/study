#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#define endl '\n'
#define INF 2000000000

using namespace std;

bool compare(set<int> a, set<int> b){
  return a.size() < b.size();
}

vector<int> solution(string str) {
  vector<set<int>> v;
  set<int> s;
  string num = "";
  for (int i=1; i<str.length()-1; i++){
    
    if (str[i] == '{') {
      s.clear();
    }
    else if (str[i] == ',' && str[i-1] == '}') {
      s.insert(stoi(num));
      num = "";
      v.push_back(s);
    }
    else if (str[i] == ',') {
      s.insert(stoi(num));
      num = "";
    }
    else if (i == str.length()-2) {
      s.insert(stoi(num));
      num = "";
      v.push_back(s);
    }
    else {
      num.push_back(str[i]);
    }
  }

  sort(v.begin(), v.end(), compare);

  int srt = 0;
  vector<int> ans;
  for (int j=0; j<v.size(); j++){
    int num = *v[srt].begin();
    ans.push_back(num);
    for (int i=srt; i<v.size(); i++){
      v[i].erase(v[i].find(num));
    }
    srt++;
  }

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";

  vector<int> ans = solution(s);

  for (auto a : ans){
    cout << a;
  }

}