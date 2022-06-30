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


/* 
1. 정지된 유저 계산, 한 유저 중복신고 불가
2. 정지된 유저를 신고한 유저에게 메일
 */
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
  map<string, int> mapping;
  vector<vector<int>> report_list;
  vector<int> report_cnt;
  report_list.resize(id_list.size()+1);
  report_cnt.resize(id_list.size()+1);

  int idx = 0;
  for (auto id : id_list) {
    mapping[id] = ++idx;
  }

  set<string> sreport(report.begin(), report.end());

  for (auto rep: sreport) {
    int pos = 0;
    while (rep[pos] != ' ') {
      pos++;
    }
    int fr = mapping[rep.substr(0,pos)];
    int to = mapping[rep.substr(pos+1)];

    report_list[fr].push_back(to);
    report_cnt[to]++;
  }

  vector<int> ans;
  for (int i=1; i<=id_list.size(); i++) {
    int cnt = 0;
    for (auto user : report_list[i]) {
      if (report_cnt[user] >= k) cnt++;
    }
    ans.push_back(cnt);
  }
  
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}