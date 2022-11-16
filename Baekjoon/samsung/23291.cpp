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

int n,k;
vector<vector<int>> cols = {{}};
// 공중 부양 가능한 블럭
vector<vector<int>> rows;
vector<vector<int>> moves;

/* 
1. 물고기 수가 가장 작은 어항들에 물고기 1마리
2. 가장 왼쪽에 있는 어항을 그 어항의 오른쪽에 있는 어항의 위에 올려 놓음 
3. 왼쪽공중부양 + 시계90도 회전
4. 물고기 조절(인접한 칸의 차이를 5로 나누어 몫이 0보다 크면 많은 곳에서 적은 곳으로 몫 만큼 이동)
5. 일자 정렬(아래~위, 왼~오)
6. 가운데 공중부양 + 시계 180도 회전
7. 물고기 조절
8. 일자 정렬
 */

void addFish() {
  int minFish = INF;
  vector<int> minIdx;
  for (int i=0; i<cols[0].size(); i++) {
    int c = cols[0][i];
    if (c <= minFish) {
      if (c < minFish) {
        minIdx.clear();
      }
      minIdx.push_back(i);
      minFish = c;
    }
  }
  for (auto idx : minIdx) {
    cols[0][idx]++;
  }
}

void updateRow() {
  // col 마지막 원소의 길이 만큼 row가 새로 생김
  rows.clear();
  for (int i=0; i<cols[cols.size()-1].size(); i++) {
    vector<int> row;
    for (int j=0; j<cols.size(); j++){
      row.push_back(cols[j][i]);
    }
    rows.push_back(row);
  }
}

void stackOne() {
  cols.push_back({cols[0][0]});
  cols[0].erase(cols[0].begin());
  updateRow();
}

// 공중부양 -> 90도 회전 -> 쌓기
void flyAndStack() {

  // rows의 원소의 길이가 남은 길이보다 작거나 같아야 더 진행 가능
  while (rows[0].size() <= cols[0].size() - rows.size()) {

    // rows 원소 수 만큼 공중 부양 -> cols 첫 행에서 삭제
    cols[0].erase(cols[0].begin(), cols[0].begin() + rows.size());
    
    // 첫 행만 남기기
    cols = {cols[0]};
    
    // 역순으로 row의 원소들 col에 삽입 = 공중부양 후 90도 회전 후 쌓기
    for (int i=rows.size()-1; i>=0; i--) {
      cols.push_back(rows[i]);
    }

    updateRow();
  }
}

void getMove(int rc, vector<vector<int>> v) {

  for (int i=0; i<v.size(); i++) {
    for (int j=0; j<v[i].size()-1; j++) {
      int a = v[i][j];
      int b = v[i][j+1];
      int d= abs(a - b)/5;
      if (d > 0) {
        if (a > b) moves.push_back({rc,i,j,j+1,d});
        else moves.push_back({rc,i,j+1,j,d});
      }
    }
  }
}

// 이동해야할 경우 미리 계산 후 한번에 정산
// {rc,index,fr,to,cnt}
void fishMove() {
  moves.clear();
  getMove(0,cols);
  getMove(1,rows);
  
  for (int i=0; i<moves.size(); i++) {

    int rc = moves[i][0];
    int idx = moves[i][1];
    int fr = moves[i][2];
    int to = moves[i][3];
    int cnt = moves[i][4];
    if (rc == 0) {
      cols[idx][fr] -= cnt;
      cols[idx][to] += cnt;
    }
    else {
      cols[fr][idx] -= cnt;
      cols[to][idx] += cnt;
    }
  }

  updateRow();
}

void makeLine() {
  vector<int> tmp;

  for (auto row : rows) {
    for (auto r : row){
      tmp.push_back(r);
    }
  }
  for (int i=rows.size(); i<cols[0].size(); i++) {
    tmp.push_back(cols[0][i]);
  }

  cols = {tmp};
  rows.clear();
}

void flyAndStack2() {
  int t = 2;
  while (t--) {
    for (int i=cols.size()-1; i>=0; i--) {
      vector<int> half(cols[i].begin(), cols[i].begin()+cols[i].size()/2);
      cols[i].erase(cols[i].begin(), cols[i].begin()+cols[i].size()/2);
      reverse(half.begin(), half.end());
      cols.push_back(half);
    }
  }
  updateRow();
}

int getDiff() {
  int Max = 0;
  int Min = INF;
  for (auto col : cols[0]) {
    Max = max(Max, col);
    Min = min(Min, col);
  }
  return Max - Min;
}

void makeLine2() {
  vector<int> tmp;

  for (auto row : rows) {
    for (auto r : row){
      tmp.push_back(r);
    }
  }

  cols = {tmp};
}

int solution() {
  int ans = 0;
  while(1) {
    ans++;
    
    addFish();
    stackOne();
    flyAndStack();
    fishMove();
    makeLine();
    flyAndStack2();
    fishMove();
    makeLine2();

    if (getDiff() <= k) return ans;
  }
  return -1;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");
  ifstream cin;
  cin.open("input.txt");

  cin >> n >> k;

  for (int i=0; i<n; i++){
    int a;
    cin >> a;
    cols[0].push_back(a);
  }

  cout << solution();
}