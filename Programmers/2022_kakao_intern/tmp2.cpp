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

int idxs[3150][3150][3];

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

    // 효율성 좋은 3경우만 넣기
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

    for (auto idx : {maxXIdx,maxYIdx,maxAvgIdx}) {
      int needX = problems[idx][0];
      int needY = problems[idx][1];
      int gainX = problems[idx][2];
      int gainY = problems[idx][3];
      int solveCost = problems[idx][4];

      int nx = x+gainX;
      int ny = y+gainY;

      if (memo[x][y] < cost) continue;

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

  // 효율성 좋은 것들 미리계산
  for (int x=0; x<maxAlp; x++)
    for (int y=0; y<maxCop; y++){
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
      idxs[x][y][0] = maxX;
      idxs[x][y][0] = maxY;
      idxs[x][y][0] = maxAvg;
    }
  

  return bfs(alp,cop,maxAlp,maxCop,problems);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}