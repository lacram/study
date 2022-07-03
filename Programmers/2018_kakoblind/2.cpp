#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#define endl '\n'
#define INF 2000000000

using namespace std;

string getStr(string str) {
  string ans = "";

  for (int i=0; i<str.length(); i++){
    if (0 <= str[i]-'A' && str[i]-'A' <= 25) {
      ans.push_back(str[i]);
    }
    else if (0 <= str[i]-'a' && str[i]-'a' <= 25) {
      ans.push_back(str[i]-32);
    }
    else return "X";
  }
  return ans;
}

int solution(string str1, string str2) {
  map<string,int> ma;
  map<string,int> mb;

  for (int i=0; i<str1.length()-1; i++){
    string s = str1.substr(i,2);
    s = getStr(s);
    if (s != "X")
      ma[s]++;
  }
  for (int i=0; i<str2.length()-1; i++){
    string s = str2.substr(i,2);
    s = getStr(s);
    if (s != "X")
      mb[s]++;
  }
  // 합집합
  int y = 0;
  for (auto item : ma){
    y += item.second;
  }
  for (auto item : mb){
    y += item.second;
  }
  // 교집합
  int x = 0;
  for (auto item : ma){
    string key = item.first;
    if (mb[key] != 0) x += min(ma[key], mb[key]);
  }
  y -= x;
  
  if (x == 0 && y == 0) return 65536;
  return floor((double)x/y*65536);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution("FRANCE","french");

}