#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#define endl '\n'
#define INF 2000000000

using namespace std;

/* 
5,5에서 시작
visited[x][y][dir]을 기억
 */

int visited[12][12][4];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
map<char,int> mapping = {
  {'R',0},{'D',1},{'L',2},{'U',3}
};

int solution(string dirs) {

  int x=5,y=5;
  int ans = 0;
  for (auto dir : dirs) {
    int d = mapping[dir];

    int nx = x + dx[d];
    int ny = y + dy[d];

    if (nx < 0 || ny < 0 || nx > 10 || ny > 10) continue;

    if (!visited[x][y][d]) ans++;
    visited[x][y][d] = 1;
    for (int i=0; i<4; i++) {
      if (d == i) visited[nx][ny][(d+2)%4] = 1;
    }

    x = nx;
    y = ny;
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}