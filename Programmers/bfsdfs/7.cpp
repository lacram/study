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

int tvisited[50][50];
int bvisited[50][50];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<vector<int>> game_board;
vector<vector<int>> table;
int n;

/* 
1. board, table에서 각각 블럭형태로 분리해 배열에 저장
2. 정렬해 비교
3. 회전 후 정렬해 비교 x 3
 */

vector<pair<int,int>> tblock;
vector<vector<pair<int,int>>> tblocks;
vector<pair<int,int>> bblock;
vector<vector<pair<int,int>>> bblocks;

void dfs(int x, int y) {
  tblock.push_back({x,y});
  tvisited[x][y] = 1;

  for (int i=0; i<4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
  
    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
    if (!table[nx][ny]) continue;
    if (tvisited[nx][ny]) continue;

    dfs(nx,ny);
  }
}

void dfs2(int x, int y) {
  bblock.push_back({x,y});
  bvisited[x][y] = 1;

  for (int i=0; i<4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
  
    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
    if (game_board[nx][ny]) continue;
    if (bvisited[nx][ny]) continue;

    dfs2(nx,ny);
  }
}

// 비교 위해 시작점을 {0,0}으로 맞추기
void moveBlock(vector<pair<int,int>>& block) {
  sort(block.begin(), block.end());
  int a = block[0].first;
  int b = block[0].second;
  for (int k=0; k<block.size(); k++) {
    block[k].first -= a;
    block[k].second -= b;
  }
}

void rotate(vector<pair<int,int>>& block) {
  for (int i=0; i<block.size(); i++) {
    int x = block[i].first;
    int y = block[i].second;

    block[i].first = n-y;
    block[i].second = x;
  }
  moveBlock(block);
}

bool compare(vector<pair<int,int>> v1, vector<pair<int,int>> v2) {
  for (int i=0; i<v1.size(); i++) {
    if (v1[i] != v2[i]) return false;
  }
  return true;
}

int getAns() {
  int ans = 0;
  int tfind[1000] = {0};
  int bfind[1000] = {0};

  for (int i=0; i<tblocks.size(); i++) {
    for (int j=0; j<bblocks.size(); j++) {
      if (tfind[i] || bfind[j]) continue;
      if (tblocks[i].size() != bblocks[j].size()) continue;

      for (int k=0; k<4; k++) {
        if (compare(tblocks[i],bblocks[j])) {
          ans += tblocks[i].size();
          tfind[i] = 1;
          bfind[j] = 1;
          break;
        }
        rotate(tblocks[i]);
      }
    }
  }
  return ans;
}

int solution(vector<vector<int>> g, vector<vector<int>> t) {
  n = t.size();
  game_board = g;
  table = t;

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) {
      if (tvisited[i][j]) continue;
      if (!table[i][j]) continue;

      tblock.clear();
      dfs(i,j);
      moveBlock(tblock);
      tblocks.push_back(tblock);
    }

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) {
      if (bvisited[i][j]) continue;
      if (game_board[i][j]) continue;

      bblock.clear();
      dfs2(i,j);
      moveBlock(bblock);
      bblocks.push_back(bblock);
    }

  sort(tblocks.begin(), tblocks.end());
  sort(bblocks.begin(), bblocks.end());
  
  return getAns();
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution({{1,1,0,0,1,0},{0,0,1,0,1,0},{0,1,1,0,0,1},{1,1,0,1,1,1},{1,0,0,0,1,0},{0,1,1,1,0,0}} ,  {{1,0,0,1,1,0},{1,0,1,0,1,0},{0,1,1,0,1,1},{0,0,1,0,0,0},{1,
1,0,1,1,0},{0,1,0,0,0,0}});

}