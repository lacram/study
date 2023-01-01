#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;


vector<vector<int>> parent(100);
vector<vector<int>> tree(100);
vector<int> totaltime(100);
vector<int> spendtime(100);
vector<int> sorting;
vector<bool> visited(100);

void dfs(int now){
  visited[now] = 1;

  for (int i=0; i<tree[now].size(); i++)
    if (!visited[tree[now][i]])
      dfs(tree[now][i]);

  sorting.push_back(now);
}

int solve(){

  for (auto work : sorting){
    int ret = 0;
    for (auto precede : parent[work]) 
      ret = max(ret, totaltime[precede]);
    totaltime[work] = ret + spendtime[work];
  }
  return totaltime[sorting[sorting.size()-1]];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  string str;
  char c;
  int n;

  while (getline(cin, str)) {
    c = str[0];
    n = str[2] - '0';
    spendtime[c-'A'] = n;
    
    if (str.length() <= 3) continue;

    string s = str.substr(4);
    for (int i=0; i<s.length(); i++){
      parent[c-'A'].push_back(s[i]-'A');
      tree[s[i]-'A'].push_back(c-'A');
    }
	}

	dfs(0);

  reverse(sorting.begin(), sorting.end());

  cout << solve();
}