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

/* bfs
1. 현재 노드와 트랩의 상태, 비용을 queue에 담기
t1 t2
x  x  정
x  o  역
o  x  역
o  o  정
2. 일반 방은 트랩이 항상 꺼져있는 방임
3. 다익스트라
 */

vector<pair<int,int>> tree[1001];
vector<pair<int,int>> Rtree[1001];
bool isTrap[1001];

int bfs(int srt, int end) {
  // 비용, {현위치, 트랩상태}
  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

  pq.push({0,srt,0});

  while (!pq.empty()) {
    int total = pq.top()[0];
    int now = pq.top()[1];
    int state = pq.top()[2];

    if (now == end) return total;

    // 둘다 트랩off 거나 둘다 on
    for (auto [next, cost] : tree[now]) {
      // off일 경우 &시 0, on일 경우 &시 자기자신
      if (!(state | (1<<now) == 0 && state | (1<<next) == 0) &&
         !(state | (1<<now) && state | (1<<next))) continue;

      if (isTrap[next]) pq.push(total+cost,next,state|(1<<))
    }

    // 둘중 하나만 on
    for (auto [next, cost] : Rtree[now]) {
      // off일 경우 &시 0, on일 경우 &시 자기자신
      if (state | (1<<now) == 0 && state | (1<<next) == 0) continue;
      if (state | (1<<now) && state | (1<<next)) continue;
    }
  }
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {

  sort(roads.begin(), roads.end());

  for (auto road : roads) {
    int fr = road[0]-1;
    int to = road[1]-1;
    int cost = road[2];

    tree[fr].push_back({to,cost});
    Rtree[to].push_back({fr,cost});
  }

  for (int i=0; i<traps.size(); i++) {
    isTrap[traps[i]-1] = 1;
  }

  return bfs(start-1,end-1);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}