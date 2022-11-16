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

vector<vector<int>> tree;
vector<int> result;
bool visited[100001];

// 다익스트라 
// 도착지에서 여러 출발지까지
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
  tree.resize(n+1);
  result.resize(n+1,INF);

  for (auto road : roads) {
    int a = road[0];
    int b = road[1];

    tree[a].push_back(b);
    tree[b].push_back(a);

  }

  // 거리, 위치
  priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> pq;

  pq.push({0,destination});
  result[destination] = 0;

  while (!pq.empty()) {
    int dist = pq.top().first;
    int now = pq.top().second;

    pq.pop();
    
    for (auto next : tree[now]) {
      if (result[next] > dist + 1) {
        result[next] = dist+1;
        pq.push({dist+1,next});
      }
    }
  }
  vector<int> ans;
  for (auto source : sources) {
    if (result[source] == INF) ans.push_back(-1);
    else ans.push_back(result[source]);
  }
  
  return ans;
}


int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution(5 ,      {{1, 2}, {1, 4}, {2, 4}, {2, 5}, {4, 5}} ,       {1, 3, 5}   ,    5 );

}