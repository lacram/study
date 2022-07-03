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

/*
1. 양 끝 {}제외
2. 숫자완성시 추가
3. 빈도수가 많은 순으로 정렬
*/
vector<int> solution(string s) {
  // 빈도수, 숫자
  vector<vector<int>> v;
  // 숫자,idx
  map<int,int> m;
  int idx = 1;

  for (int i=1; i<s.size()-1; i++) {
    string snum = "";

    int pos = i;
    while (isdigit(s[pos])) {
      snum.push_back(s[pos++]);
    }

    // 숫자 발견시
    if (snum != "") {
      int num = stoi(snum);

      // 기존에 발견한 숫자이면
      if (m[num]) {
        v[m[num]-1][0]++;
      }
      // 기존에 발견한 숫자가 아니면
      else {
        v.push_back({1,num});
        m[num] = idx++;
      }

      i = pos-1;
    }
  }

  sort(v.begin(), v.end(), greater<>());

  vector<int> ans;

  for (auto a : v) {
    ans.push_back(a[1]);
  }

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");

}