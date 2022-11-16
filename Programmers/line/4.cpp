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
#define INF 1000000

using namespace std;

/* 
1. 홀드만 따로 빼내기
2. 각 홀드 간에 이동가능 여부 구하기
3. 플로이드 와샬
 */

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<string> wall;

bool canMove(int x1, int y1, int x2, int y2) {
  if (abs(x1-x2+y1-y2) > 3) return false;

  // 상하좌우 인접
  for (int i=0; i<4; i++) {
    int nx = x1 + dx[i];
    int ny = y1 + dy[i];

    if (x2 == nx && y2 == ny) return true;
  }
  // 좌우로 2,3칸
  if ((x1 == x2) && (abs(y1-y2) == 2 || abs(y1-y2) == 3)) {
    for (int i=min(y1,y2); i<=max(y1,y2); i++) {
      if ((x1-1 < 0) || wall[x1-1][i] == 'X') return false;
    }
    for (int i=min(y1,y2)+1; i<max(y1,y2); i++) {
      if (wall[x1][i] == 'X') return false;
    }
    return true;
  }
  // 위로 2칸
  if ((y1 == y2) && (x1 - x2 == 2)) {
    if ((x1-1 < 0) || wall[x1-1][y1] == 'X') return false;
    return true;
  }
  // 대각선 오른위
  if ((x1 - 1 == x2) && (y1 + 1 == y2)) {
    if (wall[x1][y2] == 'X') return false;
    if (wall[x2][y1] == 'X') return false;
    return true;
  }
  // 대각선 왼위
  if ((x1 - 1 == x2) && (y1 - 1 == y2)) {
    if (wall[x1][y2] == 'X') return false;
    if (wall[x2][y1] == 'X') return false;
    return true;
  }

  return false;
}

vector<vector<int>> solution(vector<string> wal) {
  wall = wal;
  int h = wall.size();
  int w = wall[0].size();

  // 홀드만 따로 빼내기
  vector<pair<int,int>> v;
  for (int i=h-1; i>=0; i--)
    for (int j=0; j<w; j++) {
      if (wall[i][j] == 'H') {
        v.push_back({i,j});
      }
    }
  
  vector<vector<int>> dist;
  dist.resize(v.size());
  for (int i=0; i<dist.size(); i++) {
    dist[i].resize(v.size());
    for (int j=0; j<v.size(); j++) {
      dist[i][j] = INF;
      if (i == j) dist[i][j] = 0;
    }
  }

  // 각 홀드 간에 이동가능 여부 구하기
  for (int i=0; i<v.size(); i++)
    for (int j=0; j<v.size(); j++) {
      int x1 = v[i].first;
      int y1 = v[i].second;
      int x2 = v[j].first;
      int y2 = v[j].second;

      if (canMove(x1,y1,x2,y2)) {
        dist[i][j] = 1;
      }
    }
  
  for (int k=0; k<v.size(); k++)
    for (int i=0; i<v.size(); i++)
      for (int j=0; j<v.size(); j++) {
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
      }
  
  int idx = 0;
  vector<vector<int>> ans;
  ans.resize(h);
  for (int i=0; i<h; i++) {
    ans[i].resize(w);
  }

  for (int i=0; i<h; i++)
    for (int j=0; j<w; j++) {
      if (wall[i][j] == 'H') {
        if (dist[0][idx] != INF) {
          ans[i][j] = dist[0][idx]+1;
        } else{
          ans[i][j] = -1;
        }
        idx++;
      }
    }
  
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution({"H.H",".HX","H.H"});

}