#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#define endl '\n'

using namespace std;

int n,k,l;
int apple[101][101];
int board[101][101];
int rotateT[100];
char dir[100];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
deque<pair<int,int>> snake;

int solve(int x, int y){

  snake.push_back(make_pair(1,1));
  
  int checkRT=0;
  int time = 0;
  int d = 0;

  while (1){
    time++;
    int nx = x+dx[d];
    int ny = y+dy[d];

    // 벽에 닿음
    if (nx < 1 || nx > n || ny < 1 || ny > n) break;
    
    // 몸에 닿음
    bool fin = 0;
    for (int i=0; i<snake.size(); i++)
      if (make_pair(nx,ny) == snake[i]) {
        fin = 1;
        break;
      }
    if (fin) break;

    // 이동
    snake.push_back(make_pair(nx,ny));
    if (apple[nx][ny]) {
      apple[nx][ny] = 0;
    }
    else{
      snake.pop_front();
    }

    if (checkRT < l && rotateT[checkRT] == time){
      if (dir[checkRT] == 'D'){
        if (d == 3) d = 0;
        else d++;
      }
      else{
        if (d == 0) d = 3;
        else d--;
      }
      checkRT++;
    }
    x = nx;
    y = ny;
  }
  return time;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> k;

  for (int i=0; i<k; i++){
    int a,b;
    cin >> a >> b;
    apple[a][b] = 1;
  }

  cin >> l;
  for (int i=0; i<l; i++){
    cin >> rotateT[i];
    cin >> dir[i];
  }

  cout << solve(1,1);
}