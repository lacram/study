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

/* 이분탐색 + dfs
 */

vector<int> tree[10001];
vector<int> value(10001);
int root;

pair<int,int> compare (pair<int,int> p1 , pair<int,int> p2) {
  return p1.second < p2.second ? p1 : p2;
}

// pnum으로 최대한 그룹을 모았을 때 {그룹수,인원수}
pair<int,int> dfs(int now, int pnum) {
  // 자식이 없을 경우
  if (now == -1) return {1,0};
  // 현재 노드의 값이 기준보다 클 경우
  if (pnum < value[now]) return {10001,0};

  int left = tree[now][0];
  int right = tree[now][1];

  pair<int,int> pleft = dfs(left,pnum);
  pair<int,int> pright = dfs(right,pnum);
  // pnum 인원수 gnum 그룹수
  int lgnum = pleft.first;
  int lpnum = pleft.second;
  int rgnum = pright.first;
  int rpnum = pright.second;
  int npnum = value[now];

  // 왼,오,자신
  if (lpnum+rpnum+npnum <= pnum) return {lgnum+rgnum-1, lpnum+rpnum+npnum};

  // 왼 or 오, 자신
  // 둘중 더 작은 그룹 선택
  if (lpnum+npnum <= pnum || rpnum+npnum <= pnum) {
    pair<int,int> p = compare(pleft,pright);
    return {lgnum+rgnum, p.second+npnum};
  }

  // 자신
  return {lgnum+rgnum+1, npnum};
}

int solution(int k, vector<int> num, vector<vector<int>> links) { 
  bool used[10001] = {0};

  for (int i=0; i<num.size(); i++) {
    value[i] = num[i];
  }

  for (int i=0; i<links.size(); i++) {
    for (int j=0; j<2; j++){
      int node = links[i][j];
      tree[i].push_back(node);
      if (node != -1) used[node] = 1;
    }
  }

  for (int i=0; i<num.size(); i++) {
    if (!used[i]) root = i;
  }

  int lo = 1;
  int hi = 100000000;

  while (lo <= hi) {
    int mid = (lo+hi)/2;
    if (dfs(root,mid).first <= k) hi = mid -1;
    else lo = mid + 1;
  }

  return lo;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution(2    ,   {6, 9, 7, 5}   , {{-1, -1}, {-1, -1}, {-1, 0}, {2, 1}});
}