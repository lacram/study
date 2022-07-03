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

vector<vector<int>> board;
vector<int> cards;
vector<pair<int,int>> point[7];


int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

/* 
1. next_permutation으로 모든 경우의 수 찾기
2. bfs로 카드짝 최단경로 찾기
3. 둘다 삭제 
*/

// 해당방향 최대로 갈 수 있는 좌표 
pair<int,int> getPos(int x, int y, int dir) {
  int nx,ny;
  for (int i=1; i<=4; i++) {  
    nx = x+dx[dir]*i;
    ny = y+dy[dir]*i;

    if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) return {nx-dx[dir], ny-dy[dir]};
    if (board[nx][ny]) return {nx,ny};
  }
}

int dfs(int x1, int y1, int x2, int y2) {
  // 거리, {좌표}
  priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

  pq.push({0,{x1,y1}});

  while (!pq.empty()) {
    int cost = pq.top().first;
    int x = pq.top().second.first;
    int y = pq.top().second.second;
    pq.pop();

    if (x == x2 && y == y2) return cost;

    for (int i=0; i<4; i++) {
      
      // 한칸 또는 갈 수 있는 곳까지
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;

      pq.push({cost+1,{nx,ny}});

      // 더이상 진행 불가
      if (board[nx][ny]) continue;

      pair<int,int> p = getPos(x,y,i);
      nx = p.first;
      ny = p.second;

      pq.push({cost+1,{nx,ny}});
    }
  }
}

int sol(int idx, int x, int y, int total) {
  if (idx == cards.size()) return total;

  int num = cards[idx];

  int cx1 = point[num][0].first;
  int cx2 = point[num][1].first;
  int cy1 = point[num][0].second;
  int cy2 = point[num][1].second;

  vector<int> ans;
  // 시작점에서 카드1까지 최단거리 + 카드1에서 카드2까지 최단거리
  ans.push_back(dfs(x,y,cx1,cy1)+dfs(cx1,cy1,cx2,cy2));
  // 시작점에서 카드2까지 최단거리 + 카드2에서 카드1까지 최단거리
  ans.push_back(dfs(x,y,cx2,cy2)+dfs(cx2,cy2,cx1,cy1));
  
  board[cx1][cy1] = 0;
  board[cx2][cy2] = 0;

  int minCost =  min(sol(idx+1,cx2,cy2,total+ans[0]), sol(idx+1,cx1,cy1,total+ans[1]));

  board[cx1][cy1] = num;
  board[cx2][cy2] = num;

  return minCost;
}

int solution(vector<vector<int>> b, int r, int c) {
  board = b;
  
  set<int> s;
  
  for (int i=0; i<board.size(); i++)
    for (int j=0; j<board.size(); j++)
      // 카드발견시
      if (board[i][j]) {
        int num = board[i][j];
        s.insert(num);
        point[num].push_back({i,j});
      }
  
  cards = {s.begin(), s.end()};
  sort(cards.begin(), cards.end());

  int ans = INF;
  do {
    board = b;

    ans = min(ans, sol(0,r,c,0));

  }while(next_permutation(cards.begin(), cards.end()));
  
  return ans+cards.size()*2;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution({{1,0,0,3},{2,0,0,0},{0,0,0,2},{3,0,1,0}} ,      1  ,     0);

}