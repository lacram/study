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

vector<vector<int>> row(100);
vector<vector<int>> col(100);
map<int,int> cnt;

bool compare(int a, int b) {
  if (cnt[a] == cnt[b]) {
    return a < b;
  }
  return cnt[a] < cnt[b];
}

vector<int> sortLine(vector<int> line) {
  set<int> s(line.begin(), line.end());
  cnt.clear();
  for (auto n : line) {
    cnt[n]++;
  }
  vector<int> tmp(s.begin(), s.end());
  sort(tmp.begin(), tmp.end(), compare);
  vector<int> sortedLine;

  for (auto t : tmp) {
    sortedLine.push_back(t);
    sortedLine.push_back(cnt[t]);
    if (sortedLine.size() == 100) break;
  }

  return sortedLine;
}

void setRow() {
  for (int i=0; i<maxRowCnt; i++){
    vector<int> tmp;
    for (int j=0; j<maxColCnt; j++) {
      if (col[j].size() >= i+1) tmp.push_back(col[j][i]);
    }
    row[i] = tmp;
  }
}

void setCol() {
  for (int i=0; i<maxColCnt; i++){
    vector<int> tmp;
    for (int j=0; j<maxRowCnt; j++) {
      if (row[j].size() >= i+1) tmp.push_back(row[j][i]);
    }
    col[i] = tmp;
  }
}

void operationR() {
  maxColCnt = 0;
  for (int i=0; i<maxRowCnt; i++) {
    row[i] = sortLine(row[i]);
    maxColCnt = max(maxColCnt, (int) row[i].size());
  }
}

void operationC() {
  maxRowCnt = 0;
  for (int i=0; i<maxColCnt; i++) {
    col[i] = sortLine(col[i]);
    maxRowCnt = max(maxRowCnt, (int) col[i].size());
  }
}

bool finished() {
  if (row[r-1].size() <= c-1) return false;
  return row[r-1][c-1] == k;
}

void print() {
  cout << "maxRowCnt " << maxRowCnt << "maxColCnt " << maxColCnt << endl;
  for (int i=0; i<maxRowCnt; i++) {
    for (int j=0; j<row[i].size(); j++) {
      cout << row[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  // for (int i=0; i<maxColCnt; i++) {
  //   for (int j=0; j<col[i].size(); j++) {
  //     cout << col[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;
}

int solution() {
  int time = 0;

  while (!finished()) {
    if (time > 100) return -1;

    if (maxRowCnt >= maxColCnt) {
      operationR();
      setCol();
    }
    else {
      operationC();
      setRow();
    }

    print();

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
    for (int j=0; j<3; j++) {
      int a;
      cin >> a;
      row[i].push_back(a);
    }
  }

  for (int i=0; i<3; i++){
    for (int j=0; j<3; j++)
      col[i].push_back(row[j][i]);
  }

  cout << solution();
}