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
#define INF 10000000

using namespace std;

vector<vector<string>> subways;
int dp[1001][1001];

vector<string> getLine(string str) {
  int pos;
  vector<string> v;
  while((pos = str.find(" ")) != string::npos) {
    v.push_back(str.substr(0,pos));
    str = str.substr(pos+1);
  }
  v.push_back(str);
  return v;
}

bool canGo(vector<string> v1, vector<string> v2) {
  for (auto a : v1) {
    for (auto b : v2) {
      if (a == b) return true;
    }
  }
  return false;
}

int getLine(int start) {
  for (int i=0; i<subways.size(); i++) {
    for (int j=0; j<subways[i].size(); j++)
      if (stoi(subways[i][j]) == start) {
        return i;
      }
  }
}

int solution(vector<string> subway, int start, int end) {
  int n = subway.size();

  for (int i=0; i<1001; i++)
    for (int j=0; j<1001; j++)
      dp[i][j] = INF;

  for (auto s: subway) {
    subways.push_back(getLine(s));
  }

  for (int i=0; i<subways.size(); i++)
    for (int j=i+1; j<subways.size(); j++) {
      if (canGo(subways[i], subways[j])) {
        dp[i][j] = 1;
      }
    }
  
  for (int k=0; k<n; k++)
    for (int i=0; i<n; i++)
      for (int j=0; j<n; j++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }

  return dp[getLine(start)][getLine(end)] != INF ? dp[getLine(start)][getLine(end)] : 0;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution({"0 1 2 3 4", "1 12 13 14"}, 2, 12);

}