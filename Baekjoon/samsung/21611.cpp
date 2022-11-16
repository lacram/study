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

int n,m;
int board[49][49];
vector<pair<int,int>> magic;
vector<int> line = {-1};
int ans[4];


//  가중치
int weight[4] = {7,3,1,5};
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

void getLine() {
  int x = n/2;
  int y = n/2;
  int cnt = 0;
  int len = 1;

  while (1) {
    for (int i=0; i<4; i++) {
      for (int j=0; j<len; j++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n || !board[nx][ny]) return;
      
        line.push_back(board[nx][ny]);
        x = nx;
        y = ny;
      }

      if (i == 1 || i == 3) {
        len++;
        cnt = 0;
      }
    }
  }
}

void getBoard() {
  int x = n/2;
  int y = n/2;
  int cnt = 0;
  int len = 1;
  int idx = 1;

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      board[i][j] = 0;

  while (1) {
    for (int i=0; i<4; i++) {
      for (int j=0; j<len; j++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (idx >= line.size()) return;
      
        board[nx][ny] = line[idx++];
        x = nx;
        y = ny;
      }

      if (i == 1 || i == 3) {
        len++;
        cnt = 0;
      }
    }
  }
}

void print() {
  getBoard();

  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++)
      cout << board[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}

/* 
1. 블리자드(구슬 제거)
2. 구슬 이동
3. 구슬 폭발
4. 2,3 반복
5. 구슬 변화

↑, ↓, ←, →
상 하 좌 우
0, 1, 2, 3
 */


void blizzard() {
  int dir = magic[0].first;
  int cnt = magic[0].second;
  magic.erase(magic.begin());

  int pos = 0;
  for (int i=0; i<cnt; i++) {
    pos += weight[dir] + 8*i;
    if (pos >= line.size()) break;
    // 구슬 제거할 때마다 한 칸씩 당겨짐
    if (i) pos--;
    line.erase(line.begin()+pos);
  }
}

void explode() {
  // 구슬이 2개 이상일때 동작하므로 임시 구슬을 넣었다 마지막에 빼줌
  line.push_back(-2);

  while(1) {
    vector<int> tmp = {};
    vector<pair<int,int>> toExplode = {};
    int cnt = 1;
    int last = line[1];
    bool flag = true;

    for (int i=2; i<line.size(); i++) {

      if (last == line[i]) {
        cnt++;
      } else {
        // i-cnt i-1까지 같은 숫자
        if (cnt >= 4) {
          toExplode.push_back({i-cnt,cnt});
          ans[last] += cnt;
          flag = false;
        }

        last = line[i];
        cnt = 1;
      } 
    }

    if (flag) break;

    // 동시에 터트리기
    int idx = 0;
    for (int i=0; i<line.size(); i++) {
      if (idx < toExplode.size() && i == toExplode[idx].first) {
        i += toExplode[idx].second-1;
        idx++;
      }
      else tmp.push_back(line[i]);
    }
    line = tmp;
  }
  line.pop_back();
}

void changeMarble() {
  vector<int> newLine = {-1};
  // 구슬이 2개 이상일때 동작하므로 임시 구슬을 넣었다 마지막에 빼줌
  line.push_back(-2);

  int cnt = 1;
  int last = line[1];
  
  for (int i=2; i<line.size(); i++) {

    if (last == line[i]) {
      cnt++;
    } else {
      // i-cnt i-1까지 같은 숫자
      // 변화시켜 추가
      newLine.push_back(cnt);
      newLine.push_back(last);

      last = line[i];
      cnt = 1;
    } 
    if (newLine.size() > n*n) break;
  }

  line.pop_back();
  line = newLine;
  while (line.size() > n*n) {
    line.pop_back();
  }
}

int solution() {
  getLine();

  while(m--) {
    blizzard();
    explode();
    changeMarble();
    // print();
  }
  return ans[1]*1 + ans[2]*2 + ans[3]*3;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      cin >> board[i][j];
    }
  }

  for (int i=0; i<m; i++) {
    int d,s;
    cin >> d >> s;
    magic.push_back({d-1,s});
  }

  cout << solution();
}