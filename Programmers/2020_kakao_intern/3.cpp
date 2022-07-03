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

map<string, int> mapping;
vector<int> cnt;
set<string> s;
int n;
int need = 1;

bool check(){
  for (int i=1; i<=n; i++){
    if (cnt[i] < 1){
      need = i;
      return false;
    }
  }
  return true;
}

vector<int> solution(vector<string> gems) {
  for (auto gem : gems)
    s.insert(gem);
  n = s.size();

  cnt.resize(n+1,0);

  int lo = 0;
  int hi = 0;
  int idx = 1;

  vector<int> ans = {0,INF};
  
  while (hi < gems.size()){
    if (mapping[gems[hi]] == 0) {
      // 보석은 1번부터
      mapping[gems[hi]] = idx++;
    }
    cnt[mapping[gems[hi]]]++;
    if (cnt[need] && check()) {
      while(1){
        if (cnt[mapping[gems[lo]]] > 1) {
          cnt[mapping[gems[lo]]]--;
          lo++;
        }
        else {
          if (ans[1]-ans[0] > hi - lo) {
            ans[1] = hi+1;
            ans[0] = lo+1;
          }
          break;
        }
      }
    } 
    hi++;
  }
  
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  vector<int> ans = solution({"A","B","B","B","B","B","B","C","B","A"});
  cout << ans[0] << " "  << ans[1];
}