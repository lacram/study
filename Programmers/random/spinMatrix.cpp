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
a,b c,d
상 - 우로 b ~ d-1 1칸씩 밀기
우 - 하로 a ~ c-1 1칸씩 밀기
하 - 좌로 d ~ b+1 1칸씩 밀기
좌 - 상로 c ~ a+1 1칸씩 밀기

 */
vector<vector<int>> board(101, vector<int>(101));
vector<vector<int>> tmp(101, vector<int>(101));

int rotate(int a, int b, int c, int d) {
  int minNumber = INF;
  tmp = board;
  // 상
  for (int i=b; i<d; i++) {
    tmp[a][i+1] = board[a][i];
    minNumber = min(minNumber, board[a][i]);
  }
  // 우
  for (int i=a; i<c; i++) {
    tmp[i+1][d] = board[i][d];
    minNumber = min(minNumber, board[i][d]);
  }
  // 하
  for (int i=d; i>b; i--) {
    tmp[c][i-1] = board[c][i];
    minNumber = min(minNumber, board[c][i]);
  }
  // 좌
  for (int i=c; i>a; i--) {
    tmp[i-1][b] = board[i][b];
    minNumber = min(minNumber, board[i][b]);
  }
  board = tmp;
  return minNumber;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
  int k = 1;
  for (int i=1; i<=rows; i++)
    for (int j=1; j<=columns; j++)
      board[i][j] = k++;

  vector<int> answer;
  for (auto query : queries) {
    answer.push_back(rotate(query[0],query[1],query[2],query[3]));
  }
  return answer;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}