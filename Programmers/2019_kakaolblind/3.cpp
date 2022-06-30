#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#define endl '\n'
#define INF 2000000000

using namespace std;

vector<vector<int>> v;
vector<vector<int>> ans;
int n;

bool check(vector<int> v1, vector<int> v2){
  for (auto a : v1) {
    bool flag = true;
    for (auto b : v2) {
      if (a == b) flag = false;
    }
    if (flag) return false;
  }
  return true;
}

void checkUnique(vector<int> comb, vector<vector<string>> relation){
  for (int i=0; i<relation.size(); i++)
    for (int j=i+1; j<relation.size(); j++){
      // 모두 같은게 하나라도 존재하면 실패
      int cnt = 0;
      for (auto c : comb){
        if (relation[i][c] == relation[j][c]) {
          cnt++;
        }
      if (cnt == comb.size()) return;
    }
  }

  ans.push_back(comb);
}

void makeCombination(int srt, vector<int> tmp, int depth){

  if (tmp.size() == depth) {
    v.push_back(tmp);
    return;
  }

  for (int i=srt; i<n; i++){
    tmp.push_back(i);
    makeCombination(i+1, tmp, depth);
    tmp.pop_back();
  }
}

int solution(vector<vector<string>> relation) {
  n = relation[0].size();

  for (int i=1; i<=n; i++) {
    makeCombination(0,{},i);
  }

  for (auto comb : v) {
    checkUnique(comb, relation);
  }

  for (auto it = ans.begin(); it < ans.end(); it++) 
    for (auto it2 = ans.begin(); it2 < ans.end(); it2++) {
      if (it == it2) continue;

      if (check(*it,*it2)) {
        it2 = ans.erase(it2);
        it2--;
      }
    }

  return ans.size(); 
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout <<  solution({{"a", "1", "aaa", "c", "ng"}, {"b", "1", "bbb", "c", "g"}, {"c", "1", "aaa", "d", "ng"}, {"d", "2", "bbb", "d", "ng"}});


  
}