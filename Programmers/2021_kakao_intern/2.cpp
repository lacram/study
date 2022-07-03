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

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int visited[5][5];

bool dfs(vector<string> place, int x, int y, int depth){
  if (depth != 0 && place[x][y] == 'P') {
    return true;
  }
  if (depth == 2) return false;

  visited[x][y] = 1;

  bool ret = false;
  for (int i=0; i<4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 0 || ny < 0 || nx > 4 || ny > 4) continue;
    if (place[nx][ny] == 'X') continue;
    if (visited[nx][ny]) continue;

    ret |= dfs(place,nx,ny,depth+1);
  }
  visited[x][y] = 0;
  return ret;
}

vector<int> solution(vector<vector<string>> places) {
  vector<int> answer;

  for (auto place : places){
    bool flag = false;
    memset(visited, 0, sizeof(visited));
    for (int i=0; i<place.size(); i++){
      for (int j=0; j<place[i].length(); j++){
        if (place[i][j] == 'P' && dfs(place,i,j,0)) {
          flag = true;
          break;
        }
      }
      if (flag) break;
    }
    if (flag) answer.push_back(0);
    else answer.push_back(1);
  }

  return answer;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  vector<int> s = solution({{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}});

  for (auto p : s) {
    cout << p << endl;
  }
}