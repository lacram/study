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

using namespace std;

int n,m;
pair<int,int> s,f;
string board[50];
int minPassG[50][50];
int minNextG[50][50];
// 오 아 왼 위
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
set<pair<int,int>> garbage;
set<pair<int,int>> nextGarbage;

void bfs(){
  priority_queue<pair<pair<int,int>,pair<int,int>>, vector<pair<pair<int,int>,pair<int,int>>>, greater<pair<pair<int,int>,pair<int,int>>>> q;
  // 쓰레기 관통, 쓰레기 옆, 좌표
  q.push({{0,0},{s.first,s.second}});

  while (!q.empty()){
    pair<pair<int,int>,pair<int,int>> v = q.top();
    int passG = v.first.first;
    int nextG = v.first.second;
    int x = v.second.first;
    int y = v.second.second;
    q.pop();

    if (passG >= minPassG[x][y]) continue;
    if (passG == minPassG[x][y] && nextG >= minNextG[x][y]) continue;

    minPassG[x][y] = passG;
    minNextG[x][y] = nextG;

    for (int i=0; i<4; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];

      if (nx == f.first && ny == f.second){
        cout << passG << " " << nextG;
        return;
      }

      if (nx >= n || ny >= m || nx < 0 || ny < 0) continue;

      // 쓰레기 관통
      bool passGflag = (garbage.find({nx,ny}) != garbage.end());
      // 쓰레기 옆
      bool nextGflag = (nextGarbage.find({nx,ny}) != nextGarbage.end());

      if (passGflag) {        
        q.push({{passG+1,nextG},{nx,ny}});
      }
      else if (nextGflag){
        q.push({{passG,nextG+1},{nx,ny}});
      }
      else {
        q.push({{passG,nextG},{nx,ny}});
      }
    }
  }
  
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  for (int i=0; i<n; i++)
    cin >> board[i];

  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++) {
      if (board[i][j] == 'S')
        s = {i,j};
      if (board[i][j] == 'F')
        f = {i,j};
      if (board[i][j] == 'g')
        garbage.insert({i,j});
    }
  
  for (set<pair<int,int>>::iterator it = garbage.begin(); it != garbage.end(); it++){
    pair<int,int> p = *it;
    int x = p.first;
    int y = p.second;
    for (int i=0; i<4; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];
      nextGarbage.insert({nx,ny});
    }
  }
  
  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++){
      minPassG[i][j] = 2500;
      minNextG[i][j] = 2500;
    }

  bfs(); 
}