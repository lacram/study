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

vector<int> dx;
vector<int> dy;

void rotate(){
  for (int i=0; i<dx.size(); i++){
    swap(dx[i],dy[i]);
    dy[i] *= -1;
  }
}

// 시계방향 90 -> x,y좌표 뒤집고 y *-1
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
  int n = lock.size();
  int m = key.size();

  int num = 0;
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++){
      if (!lock[i][j]) num++;
    }

  if (!num) return true;

  // key의 상대위치 기록
  int nx=-1,ny;
  for (int i=0; i<m; i++)
    for (int j=0; j<m; j++)
      if (key[i][j]) {
        if (nx == -1){
          nx = i;
          ny = j;
        }
        dx.push_back(i-nx);
        dy.push_back(j-ny);
      }

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) {
      if (!lock[i][j]) {
        // 90도씩 4번 회전
        for (int t=0; t<4; t++) {
          rotate();

          // key의 모든 블럭에 대해
          for (int q=0; q<dx.size(); q++){
            int cnt = 0;
            int sx = dx[q];
            int sy = dy[q];
            for (int k=0; k<dx.size(); k++) {
              int nx = i + dx[k] - sx;
              int ny = j + dy[k] - sy;

              if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
              if (lock[nx][ny]) cnt = 10000;
              if (!lock[nx][ny]) cnt++;
            }
            if (cnt == num) return true;
          }
        }
      }
    }

  return false;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution({{0, 0, 0}, {0, 0, 0}, {1, 1, 1}} ,      {{1, 1, 0}, {1, 1, 0}, {1, 1, 0}});

}