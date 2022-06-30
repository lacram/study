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

vector<vector<int>> memo;
vector<vector<vector<int>>> idxs;

int bfs(int alp, int cop, int X, int Y, vector<vector<int>> problems) {
  

  priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

  pq.push({0,{alp,cop}});

  while (!pq.empty()) {

    int cost = pq.top().first;
    int x = pq.top().second.first;
    int y = pq.top().second.second;
    pq.pop();

    if (x >= X && y >= Y) return cost;
    if (memo[x][y] < cost) continue;

    for (auto idx : idxs[x][y]) {
      int needX = problems[idx][0];
      int needY = problems[idx][1];
      int gainX = problems[idx][2];
      int gainY = problems[idx][3];
      int solveCost = problems[idx][4];

      int nx = x+gainX;
      int ny = y+gainY;

      if (memo[nx][ny] < cost+solveCost) continue;

      memo[nx][ny] = cost+solveCost;
      pq.push({cost+solveCost,{nx,ny}});
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

  memo.resize(maxAlp+40);
  for (int i=0; i<maxAlp+40; i++){
    memo[i].resize(maxCop+40);
    for (int j=0; j<maxCop+40; j++)
      memo[i][j] = INF;
  }
  
  idxs.resize(maxAlp+40);
  for (int i=0; i<maxAlp+40; i++){
    idxs[i].resize(maxCop+40);
  }

  // 효율성 좋은 것들 미리계산
  for (int x=alp; x<maxAlp+40; x++)
    for (int y=cop; y<maxCop+40; y++){

      double maxX=0,maxY=0,maxAvg=0;
      int maxXIdx=0,maxYIdx=0,maxAvgIdx=0;
      for (int i=0; i<problems.size(); i++) {
        int needX = problems[i][0];
        int needY = problems[i][1];
        int gainX = problems[i][2];
        int gainY = problems[i][3];
        int solveCost = problems[i][4];

        // 풀 수 있는 문제
        if (x >= needX && y >= needY) {

          if (maxX < double(gainX)/solveCost) {
            maxX = double(gainX)/solveCost;
            maxXIdx = i;
          }
          if (maxY < double(gainY)/solveCost) {
            maxY = double(gainY)/solveCost;
            maxYIdx = i;
          }
          if (maxAvg < double(gainX+gainY)/solveCost) {
            maxAvg = double(gainX+gainY)/solveCost;
            maxAvgIdx = i;
          }
        }
      }
      idxs[x][y].push_back(maxAvgIdx);
      idxs[x][y].push_back(maxXIdx);
      idxs[x][y].push_back(maxYIdx);
    }
  
  int ans = bfs(alp,cop,maxAlp,maxCop,problems);
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution(0   ,    0   ,   {{0,0,2,1,2},{4,5,3,1,2},{4,11,4,0,2},{10,4,0,4,2}});


}