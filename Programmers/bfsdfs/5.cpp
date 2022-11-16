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
#define endl '\n'
#define INF 2000000000

using namespace std;

vector<vector<string>> ans;
multimap<string,string> tree;
map<string,int> visited;
int n;

void dfs(string now, vector<string> coures) {
  if (coures.size() == n) {
    ans.push_back(coures);
    return;
  }

  for (auto it=tree.lower_bound(now); it!=tree.upper_bound(now); it++) {
    string next = it->second;

    if (visited[now+next] == 0) continue;;
    
    coures.push_back(next);
    visited[now+next]--;
    dfs(next, coures);
    coures.pop_back();
    visited[now+next]++;
  }
}

vector<string> solution(vector<vector<string>> tickets) {
  set<string> s;

  for (auto ticket : tickets) {
    tree.insert({ticket[0], ticket[1]});
    visited[ticket[0]+ticket[1]]++;
  }
  n = tickets.size()+1;

  dfs("ICN",{"ICN"});
  
  sort(ans.begin(), ans.end());

  return ans[0];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution({{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"}} );

}