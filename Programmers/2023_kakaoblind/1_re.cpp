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

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
  map<char,int> m;

  int tyear = stoi(today.substr(0,4));
  int tmonth = stoi(today.substr(5,2));
  int tday = stoi(today.substr(8,2));

  int todayNum = tyear*12*28 + tmonth*28 + tday;

  for (auto term : terms) {
    int pos = term.find(" ");
    m[term[0]] = stoi(term.substr(pos+1));
  }

  vector<int> ans;
  int idx = 1;
  for (auto privacy: privacies) {
    int year = stoi(privacy.substr(0,4));
    int month = stoi(privacy.substr(5,2));
    int day = stoi(privacy.substr(8,2));
    char c = privacy[11];

    int privacyNum = year*12*28 + month*28 + day + m[c]*28 - 1;

    if (todayNum > privacyNum) ans.push_back(idx);

    idx++;
  }

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution("2022.05.19", {"A 6", "B 12", "C 3"}, {"2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"});

}