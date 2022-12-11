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

int r,c,k;
int maxRowCnt = 3;
int maxColCnt = 3;
vector<vector<int>> board(100, vector<int>(100));

/* 
R 연산: 배열 A의 모든 행에 대해서 정렬을 수행한다. 행의 개수 ≥ 열의 개수인 경우에 적용된다.
C 연산: 배열 A의 모든 열에 대해서 정렬을 수행한다. 행의 개수 < 열의 개수인 경우에 적용된다.

수의 등장 횟수가 커지는 순으로, 그러한 것이 여러가지면 수가 커지는 순으로 정렬한다
 */

bool compare(pair<int,int> p1, pair<int,int> p2) {
  if (p1.second == p2.second) return p1.first < p2.first;
  return p1.second < p2.second;
}

void sortCol(int line) {
  map<int,int> count;
  for (int i=0; i<100; i++) {
    int number = board[i][line];
    // 0인 경우 제외
    if (number) {
      count[number]++;
    }
  }
  vector<pair<int,int>> countV(count.begin(), count.end());
  sort(countV.begin(), countV.end(), compare);

  // 정렬 결과대로 삽입
  int idx = 0;
  for (auto [key, value] : countV) {
    board[idx++][line] = key;
    board[idx++][line] = value;
    if (idx >= 100) break;
  }
  // 나머지 0으로 채우기
  for (int i=idx; i<100; i++) {
    board[i][line] = 0;
  }
  maxRowCnt = max(maxRowCnt,idx);
}

void sortRow(int line) {
  map<int,int> count;
  for (int i=0; i<100; i++) {
    int number = board[line][i];
    // 0인 경우 제외
    if (number) {
      count[number]++;
    }
  }
  vector<pair<int,int>> countV(count.begin(), count.end());
  sort(countV.begin(), countV.end(), compare);

  // 정렬 결과대로 삽입
  int idx = 0;
  for (auto [key, value] : countV) {
    board[line][idx++] = key;
    board[line][idx++] = value;
    if (idx >= 100) break;
  }
  // 나머지 0으로 채우기
  for (int i=idx; i<100; i++) {
    board[line][i] = 0;
  }
  maxColCnt = max(maxColCnt,idx);
}

void operationC() {
  maxRowCnt = 0;
  for (int i=0; i<100; i++) {
    sortCol(i);
  }
}

void operationR() {
  maxColCnt = 0;
  for (int i=0; i<100; i++) {
    sortRow(i);
  }
}

bool finished() {
  return board[r-1][c-1] == k;
}

int solution() {
  int time = 0;

  while (!finished()) {
    if (time > 100) return -1;

    if (maxRowCnt >= maxColCnt) {
      operationR();
    }
    else {
      operationC();
    }

    time++;
  }
  return time;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");


  cin >> r >> c >> k;

  for (int i=0; i<3; i++){
    for (int j=0; j<3; j++)
      cin >> board[i][j];
  }

  cout << solution();
}