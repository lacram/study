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

/* bfs?
{필요한 최대 알고력, 필요한 최대 코딩력}에 최소의 시간으로 도달
현재 좌표가 problems의 요구 알,코보다 높을 경우 사용가능
 */

int bfs(int alp, int cop, int X, int Y, vector<vector<int>> problems) {
  int memo[3150][3150];
  for (int i=0; i<3150; i++)
    for (int j=0; j<3150; j++)
      memo[i][j] = INF;

  priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

  pq.push({0,{alp,cop}});

  while (!pq.empty()) {

    int cost = pq.top().first;
    int x = pq.top().second.first;
    int y = pq.top().second.second;
    pq.pop();

    if (x >= X && y >= Y) return cost;
    if (memo[x][y] < cost) continue;

    for (auto problem : problems) {
      int needX = problem[0];
      int needY = problem[1];
      int gainX = problem[2];
      int gainY = problem[3];
      int solveCost = problem[4];

      // 풀 수 있는 문제
      if (x >= needX && y >= needY) {
        int nx = x+gainX;
        int ny = y+gainY;

        if (memo[nx][ny] < cost+solveCost) continue;

        memo[nx][ny] = cost+solveCost;
        pq.push({cost+solveCost,{nx,ny}});
      }
    }
  }
}

int solution(int alp, int cop, vector<vector<int>> problems) {
  int maxAlp = 0;
  int maxCop = 0;

  for (auto problem : problems) {
    maxAlp = max(maxAlp, problem[0]);  
    maxCop = max(maxCop, problem[1]);  
  }

  // 그냥 공부하는 경우 추가
  problems.push_back({0,0,1,0,1});
  problems.push_back({0,0,0,1,1});

  return bfs(alp,cop,maxAlp,maxCop,problems);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution(10   ,   10    ,  {{10,15,2,1,2},{20,20,3,3,4}});

}