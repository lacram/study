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
/* 투포인터
1. 구간내 보석이 다 없을 경우 hi++
2. 구간내 보석이 다 있을 경우 lo++, ans, 최단구간 갱신
3. 보석 종류 수 == cnt, map으로 보석 개수 저장
 */

int cnt = 1;
vector<string> gems;
map<string,int> gemCnt;

vector<int> solution(vector<string> g) {
  gems = g;

  int lo = 0, hi = 0;
  int n = 0;
  int ans = INF;
  vector<int> v(2);

  set<string> s(gems.begin(), gems.end());
  n = s.size();
  gemCnt[gems[0]] = 1;

  while(lo <= hi && hi < gems.size()) {
    // 구간내 보석이 다 없을 경우
    if (cnt != n) {
      hi++;
      if (hi >= gems.size()) break;
      if (gemCnt[gems[hi]] == 0) cnt++;
      
      gemCnt[gems[hi]]++;
    }
    // 구간내 보석이 다 있을 경우
    else {
      if (hi-lo < ans) {
        ans = hi-lo;
        v[0] = lo+1;
        v[1] = hi+1;
      }
      gemCnt[gems[lo]]--;
      if (gemCnt[gems[lo]] == 0) cnt--;
      lo++;
    }
  }

  return v;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution({"ZZZ", "YYY", "NNNN", "YYY", "BBB"});

}