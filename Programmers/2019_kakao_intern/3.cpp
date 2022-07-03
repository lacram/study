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

vector<vector<int>> v;
int used[10] = {};
int n;
set<set<int>> s;
set<int> t;

void solve(int now){
  if (now == n) {
    s.insert(t);
    return;
  }

  for (int i=0; i<v[now].size(); i++){
    int use = v[now][i];
    if (used[use]) continue;

    used[use] = 1;
    t.insert(use);
    solve(now+1);
    t.erase(t.find(use));
    used[use] = 0;
  }
}

int solution(vector<string> user_id, vector<string> banned_id) {
  n = banned_id.size();
  memset(used, 0, sizeof(used));

  for (int i=0; i<banned_id.size(); i++){
    vector<int> tmp;

    for (int j=0; j<user_id.size(); j++){
      if (banned_id[i].length() != user_id[j].length()) continue;

      bool flag = true;
      for (int k=0; k<banned_id[i].length(); k++){
        if (banned_id[i][k] != user_id[j][k] && banned_id[i][k] != '*'){
          flag = false;
          break;
        }
      }
      if (flag){
        tmp.push_back(j);
      }
    }
    v.push_back(tmp);
  }

  solve(0);
  return s.size();
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  vector<string> b = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
  //vector<string> b = {"abcd", "adcd"};
  //vector<string> b = {"aaaaaaaa","aaaaaaab","aaaaaaac","aaaaaaad","aaaaaaae","aaaaaaaf","aaaaaaag","aaaaaaaq"};
  //vector<string> m = {"fr*d*", "abc1**"};
  vector<string> m = {"fr*d*", "*rodo","******","******"};
  //vector<string> m = {"********", "********", "********", "********", "********", "********", "********", "********"};

  cout << solution(b,m);

}