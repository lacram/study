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

int n,h,w,m,k;
int board[500][500];
int cost[9];
int soldier[125][4];
int order[10000][3];
bool visited[500][500];
set<pair<int,int>> solider0;
set<pair<int,int>> solider1;
int dx[5] = {0,1,0,-1,0};
int dy[5] = {1,0,-1,0,0};

bool bfs(int o){
  if (board[order[o][1]][order[o][2]] == -1) return false;

  priority_queue<pair<int,pair<int,int>>> pq;
  pq.push({0,{soldier[order[o][0]-1][2],soldier[order[o][0]-1][3]}});
  int team = soldier[order[o][0]-1][1];
  int energy = soldier[order[o][0]-1][0];

  while (!pq.empty()){
    int c = pq.top().first;
    int x = pq.top().second.first;
    int y = pq.top().second.second;
    pq.pop();

    for (int i=0; i<4; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];

      if (c+board[nx][ny] > energy) continue;
      if (nx == order[o][1] && ny == order[o][2]) return true;
      if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
      if (board[nx][ny] == -1) continue;
      bool flag = false;
      for (int j=0; j<5; j++){
        int nnx = nx+dx[j];
        int nny = ny+dy[j];

        if (team == 0){
          if (solider1.find({nnx,nny}) != solider1.end()) {
            flag = true;
            break;
          }
        }
        if (team == 1){
          if (solider0.find({nnx,nny}) != solider0.end()) {
            flag = true;
            break;
          }
        }
      }
      if (flag) continue;

      pq.push({c+board[nx][ny],{nx,ny}});
    }
  }
  return false;
}

void solve(){
  for (int i=0; i<k; i++){
    if (bfs(i)){
      int s = order[i][0]-1;
      if (soldier[s][1] == 0){
        solider0.erase({soldier[s][2],soldier[s][3]});
        solider0.insert({order[i][1],order[i][2]});
      }
      if (soldier[s][1] == 1){
        solider1.erase({soldier[s][2],soldier[s][3]});
        solider1.insert({order[i][1],order[i][2]});
      }
      soldier[s][2] = order[i][1];
      soldier[s][3] = order[i][2];
    }
  }
  for (int i=0; i<m; i++){
    cout << soldier[i][2] << " " << soldier[i][3] << endl;
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> h >> w;

  for (int i=0; i<h; i++)
    for (int j=0; j<w; j++)
      cin >> board[i][j];
  
  for (int i=0; i<n; i++){
    cin >> cost[i];
  }

  cin >> m;

  for (int i=0; i<m; i++)
    for (int j=0; j<4; j++)
      cin >> soldier[i][j];
  
  cin >> k;

  for (int i=0; i<k; i++)
    for (int j=0; j<3; j++)
      cin >> order[i][j];
  
  for (int i=0; i<h; i++)
    for (int j=0; j<w; j++){
      board[i][j] = cost[board[i][j]-1];
    }
  
  for (int i=0; i<m; i++){
    if (soldier[i][1] == 0){
      solider0.insert({soldier[i][2],soldier[i][3]});
    }
    if (soldier[i][1] == 1){
      solider1.insert({soldier[i][2],soldier[i][3]});
    }
  }

  solve();
}