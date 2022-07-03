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
/*
1. banid별로 해당 하는 아이디 정리
2. 모든 조합 구성
3. 중복 제거
*/

int n;
vector<string> combi;
vector<vector<int>> canBan;
int used[8];

void dfs(int depth, string str) {
  if (depth == n) {
    combi.push_back(str);
    return;
  }

  for (int i=0; i<canBan[depth].size(); i++) {
    // depth번째 벤목록에 적용되는 유저 인덱스
    int uid = canBan[depth][i];
    if (used[uid]) continue;

    used[uid] = 1;
    dfs(depth+1,str+to_string(uid));
    used[uid] = 0;

  }
}

int solution(vector<string> user_id, vector<string> banned_id) {
  n = banned_id.size();

  int idx = 0;
  for (int i=0; i<banned_id.size(); i++) {
    string bid = banned_id[i];
    vector<int> uids;

    for (int j=0; j<user_id.size(); j++) {
      string uid = user_id[j];
      if (bid.size() != uid.size()) continue;

      bool flag = true;
      for (int k=0; k<bid.size(); k++){
        if (bid[k] == '*' || bid[k] == uid[k]) continue;
        flag = false;
      }
      if (flag) uids.push_back(j);
    }

    canBan.push_back(uids);
  }

  dfs(0,"");

  set<set<char>> ans;
  for (auto comb : combi) {
    set<char> tmp;
    for (auto c : comb)
      tmp.insert(c);

    ans.insert(tmp);
  }

  return ans.size();
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}