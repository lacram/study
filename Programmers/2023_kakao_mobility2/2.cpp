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
#define INF 10000

using namespace std;

/* 
플로이드로 거리 업데이트
두점씩 고르며 최대값 계산
 */

int cost[51][51];
int visited[51];
int n;
int d;
vector<int> users;
int ans;

void flo() {
  for (int k=1; k<=n; k++)
    for (int i=1; i<=n; i++)
      for (int j=1; j<=n; j++) {
        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
      }
}

void getAns(int depth, int cnt, vector<pair<int,int>> v) {
  ans = max(ans, cnt);
  if (depth > n) {
    return;
  }

  int area1 = v[0].first;
  int area2 = v[1].first;
  int area1Limit = v[0].second;
  int area2Limit = v[1].second;
  int& peopleCount = users[depth];
  // 1번 구역 사용
  // 범위내에 있고 남은 자리가 있을시
  if (cost[area1][depth] <= d && area1Limit) {
    if (area1Limit >= peopleCount) {
      getAns(depth+1,cnt+peopleCount,{{area1,area1Limit-peopleCount}, {area2,area2Limit}});
    } else {
      peopleCount -= area1Limit;
      getAns(depth,cnt+area1Limit,{{area1,0}, {area2,area2Limit}});
      peopleCount += area1Limit;
    }
  }
  // 2번 구역 사용
  if (cost[area2][depth] <= d && area2Limit) {
    if (area2Limit >= peopleCount) {
      getAns(depth+1,cnt+peopleCount,{{area1,area1Limit}, {area2,area2Limit-peopleCount}});
    } else {
      peopleCount -= area2Limit;
      getAns(depth,cnt+area2Limit,{{area1,area1Limit}, {area2,0}});
      peopleCount += area2Limit;
    }
  }
  // 구역사용 x
  getAns(depth+1,cnt,v);
}

void dfs(int now, vector<int> v, int limit) {
  if (v.size() == 2) {
    getAns(1,0,{{v[0],limit},{v[1],limit}});
  }

  visited[now] = 1;
  for (int i=now+1; i<=n; i++) {
    v.push_back(i);
    dfs(i,v,limit);
    v.pop_back();
  }
  visited[now] = 0;
}

int solution(int N, vector<vector<int>> edges, vector<int> u, int D, int limit) {
  users = u;
  users.insert(users.begin(),-1);
  n = N;
  d = D;
  for (int i=1; i<=50; i++)
    for (int j=1; j<=50; j++) {
      if (i == j) cost[i][j] = 0;  
      else cost[i][j] = INF;
    }

  for (auto edge : edges) {
    int fr = edge[0];
    int to = edge[1];
    int dist = edge[2];

    cost[fr][to] = dist;
    cost[to][fr] = dist;
  }

  flo();
  for (int i=1; i<=n; i++) {
    dfs(i,{i},limit);
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution(3,{{1,2,1},{3,2,1}},{1,2,1},1,2);

}