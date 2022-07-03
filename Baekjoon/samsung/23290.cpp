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
#include <string>
#define endl '\n'
#define INF 2000000000
#define ll long long

using namespace std;

// 물고기 
// 상어 상하좌우 3칸
// 좌1 상3

/* 
1. 복제 시전
2. 물고기 이동(상어, 물고기냄새, 벽바깥 제외) 상하좌우대각선 1칸, 이동불가시 반시계 45도
3. 상어 상하좌우 3칸, 최종 이동후 물고기가 가장 많이 제외되는 경우 선택, 상1 좌2 하3 우4, 사전순으로 앞선 방식 선택
4. 이동하면서 물고기 삭제, 물고기 냄새 남김, 2턴후 냄새 사라짐  
5. 복제 완료
 */

int m,s;
int maxFish;
vector<vector<int>> fishs;
vector<string> sharkMove;
int fishSmell[5][5];
pair<int,int> shark;
int fishCnt[5][5];
int visited[5][5];
int fdx[8] = {0,-1,-1,-1,0,1,1,1};
int fdy[8] = {-1,-1,0,1,1,1,0,-1};
int sdx[4] = {-1,0,1,0};
int sdy[4] = {0,-1,0,1};


void copy(vector<vector<int>> copiedfishs) {
  for (auto fish: copiedfishs) {
    fishs.push_back(fish);
  }
}

bool check(int x, int y, int nturn) {
  // 벽 바깥
  if (x < 1 || y < 1 || x >= 5 || y >= 5) return true;
  // 상어
  if (x == shark.first && y == shark.second) return true;
  // 물고기 냄새
  if (fishSmell[x][y]) return true;

  return false;
}

void getSharkMoves(int x, int y, int cnt, string move, int depth) {
  if (depth == 3) {
    if (cnt >= maxFish) {
      if (cnt > maxFish) sharkMove.clear();
      maxFish = cnt;
      sharkMove.push_back(move);
    }
    return;
  }

  for (int i=0; i<4; i++) {
    int nx = x + sdx[i];
    int ny = y + sdy[i];
    bool flag = false;

    if (nx < 1 || ny < 1 || nx >= 5 || ny >= 5) continue;
    if (visited[nx][ny]) flag = true;

    visited[nx][ny]++;
    move.push_back(i+'0');
    if (flag) getSharkMoves(nx,ny,cnt,move,depth+1);
    else getSharkMoves(nx,ny,cnt+fishCnt[nx][ny],move,depth+1);
    move.pop_back();
    visited[nx][ny]--;
  }
}

int solution(){
  int t = s;

  while (s--) {
    int turn = t-s;
    // 1. 복제 시전
    vector<vector<int>> copiedfishs = fishs;
    
    // 2. 물고기 이동(상어, 물고기냄새, 벽바깥 제외) 상하좌우대각선 1칸, 이동불가시 반시계 45도
    memset(fishCnt, 0, sizeof(fishCnt));
    for (int i=0; i<fishs.size(); i++){
      int x = fishs[i][0];
      int y = fishs[i][1];
      int dir = fishs[i][2];
      bool flag = false;

      for (int j=0; j<8; j++) {
        // 시계반대방향
        int nx = x + fdx[(dir-j+8)%8];
        int ny = y + fdy[(dir-j+8)%8];

        if (check(nx,ny,turn)) continue;

        fishs[i][0] = nx;
        fishs[i][1] = ny;
        fishs[i][2] = (dir-j+8)%8;
        flag = true;
        fishCnt[nx][ny]++;
        break;
      }
      if (!flag) fishCnt[x][y]++;
    }
    
    // 3. 상어 상하좌우 3칸, 최종 이동후 물고기가 가장 많이 제외되는 경우 선택, 상1 좌2 하3 우4, 사전순으로 앞선 방식 선택
    memset(visited, 0, sizeof(visited));
    getSharkMoves(shark.first, shark.second, 0, "", 0);

    int minNum = INF;
    string minStr;
    for (auto move : sharkMove) {
      int num = stoi(move);
      if (num < minNum){
        minNum = num;
        minStr = move;
      }
    }
    sharkMove.clear();
    maxFish = 0;
    
    // 4. 이동하면서 물고기 삭제, 물고기 냄새 남김, 2턴후 냄새 사라짐  
    int x = shark.first;
    int y = shark.second;
    for (auto m : minStr) {
      vector<vector<int>> tmp;
      int dir = m-'0';
      x += sdx[dir];
      y += sdy[dir];

      for (auto fish : fishs) {
        if (x == fish[0] && y == fish[1]) continue;
        tmp.push_back(fish);
      }
      if (fishCnt[x][y]) fishSmell[x][y] = turn;

      fishs = tmp;
    }
    shark.first = x;
    shark.second = y;

    // 5. 물고기 냄새 삭제
    for (int i=1; i<5; i++)
      for (int j=1; j<5; j++) {
        if (fishSmell[i][j] == turn-2)
          fishSmell[i][j] = 0;
      }

    // 6. 복제 완료
    copy(copiedfishs);
  }

  return fishs.size();
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> m >> s;

  for (int i=0; i<m; i++){
    vector<int> fish;
    int a;  
    for (int j=0; j<3; j++){
      cin >> a;
      if (j == 2) a--;
      fish.push_back(a);
    }
    fishs.push_back(fish);
  }

  int a,b;
  cin >> a >> b;
  shark = {a,b};

  cout << solution();
}