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

/* 
n이 최대 30이므로 60분 이후에는 모든 곳이 토템의 영향을 받음
 */

vector<vector<long long>> board;
int n;

void fireTotem(int x, int y, int time) {
  for (int i=-time; i<=time; i++)
    for (int j=-time; j<=time; j++) {
      if (x+i < 0 || y+j < 0 || x+i >= n || y+j >= n) continue;
      board[x+i][y+j]++;
    }
}

void iceTotem(int x, int y, int time) {
  for (int i=-time; i<=-1; i++)
    for (int j=-(time+i); j<=(time+i); j++) {
      if (x+i < 0 || y+j < 0 || x+i >= n || y+j >= n) continue;
      board[x+i][y+j]--;
    }

  for (int i=0; i<=time; i++)
    for (int j=-(time-i); j<=(time-i); j++) {
      if (x+i < 0 || y+j < 0 || x+i >= n || y+j >= n) continue;
      board[x+i][y+j]--;
    }
}

vector<vector<long long>> solution(int a, int m, vector<vector<int>> fires, vector<vector<int>> ices) {
  n = a; 
  board.resize(n);
  for (int i=0; i<board.size(); i++) {
    board[i].resize(n);
  }

  int time = 1;
  while (time <= m && time < 60) {
    for (auto fire : fires) {
      int x = fire[0]-1;
      int y = fire[1]-1;
      fireTotem(x,y,time);
    }
    for (auto ice : ices) {
      int x = ice[0]-1;
      int y = ice[1]-1;
      iceTotem(x,y,time);
    }
    time++;
  }
  
  if (m >= 60) {
    long long diff = (fires.size()-ices.size()) * (m-time);
    for (int i=0; i<n; i++)
      for (int j=0; j<n; j++) {
        board[i][j] += diff;
      }
  }

  return board;
}



int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  vector<vector<long long>> s = solution(3,100,{{1,1}},{{3,3}});

  for (int i=0; i<3; i++){

    for (int j=0; j<3; j++){
      cout << s[i][j] << " ";

    }
    cout << endl;
  }
}