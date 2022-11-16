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
#define INF 2000000000

using namespace std;

/* 
1. 균형을 이루어야함
시소 받침대를 기준으로 좌우 구슬 수의 차이가 적을수록 더 아름답습니다.
더 많은 구슬을 사용한 장식이 더 아름답습니다.
구슬의 무게 합이 더 무거운 장식이 더 아름답습니다.
장식에 사용된 구슬의 무게들을 왼쪽부터 순서대로 담아 만든 배열이 사전 순으로 더 빠른 장식이 더 아름답습니다.

1. 구슬 순열 만들기
2. 균형을 이루는 것만 남기기
3. 정렬하기
 */

set<vector<int>> permutation;
vector<int> marbles;
int visited[10];

struct marble{
  vector<int> marbleV;
  int diff;
  int count;
  int weight;
  string str;
};
vector<marble> ans;

void dfs(vector<int> v, int depth) {
  if (depth > 0) permutation.insert(v);
  
  for (int i=0; i<marbles.size(); i++) {
    if (visited[i]) continue;
    visited[i] = 1;
    v.push_back(marbles[i]);
    dfs(v, depth+1);
    visited[i] = 0;
    v.pop_back();
  }
}

int getWeight(vector<int> v) {
  int w = 0;
  for (auto a : v) w += a;
  return w;
}

string toString(vector<int> v) {
  string str(v.begin(), v.end());
  return str;
}

void makeBalance(vector<int> v) {
  int total = 0;
  for (auto a : v) total += a;

  vector<int> leftV;
  int leftVal = 0;

  for (int i=0; i<v.size()-1; i++) {
    leftV.push_back(v[i]);
    leftVal += v[i];
    // 균형
    if (leftVal == total-leftVal) {
      marble m;
      m.marbleV = v;
      m.diff = abs(i+1-(int)(v.size()-(i+1)));
      m.count = v.size();
      m.weight = getWeight(v);
      m.str = toString(v);
      ans.push_back(m);
    }

    // 중앙 제외 균형
    if (leftVal == total-v[i+1]-leftVal) {
      marble m;
      m.marbleV = v;
      m.diff = abs(i+1-(int)(v.size()-1-(i+1)));
      m.count = v.size();
      m.weight = getWeight(v);
      m.str = toString(v);
      ans.push_back(m);
    }
  }
}

void findBalanced() {
  
  for (auto v : permutation) {
    makeBalance(v);
  }
}

/* 
1. 시소 받침대를 기준으로 좌우 구슬 수의 차이가 적을수록 더 아름답습니다.
2. 더 많은 구슬을 사용한 장식이 더 아름답습니다.
3.구슬의 무게 합이 더 무거운 장식이 더 아름답습니다.
4. 장식에 사용된 구슬의 무게들을 왼쪽부터 순서대로 담아 만든 배열이 사전 순으로 더 빠른 장식이 더 아름답습니다.
 */


bool compare(marble m1, marble m2) {
  if (m1.diff == m2.diff) {
    if (m1.count == m2.count) {
      if (m1.weight == m2.weight) {
        return m1.str < m2.str;
      }
      return m1.weight > m2.weight;
    }
    return m1.count > m2.count;
  }
  return m1.diff < m2.diff;
}

vector<int> sortAndGetFirst() {
  sort(ans.begin(), ans.end(), compare);
  marble res = ans[0];
  return res.marbleV;
}

vector<int> solution(vector<int> m) {
  marbles = m;

  dfs({},0);
  
  findBalanced();

  return sortAndGetFirst();
}



int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  vector<int> ans =  solution({1,2,3,4,4});

  for (auto a : ans) {
    cout << a << " ";
  }

}