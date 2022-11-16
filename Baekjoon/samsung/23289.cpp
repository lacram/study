#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#define endl '\n'
#define INF 2000000000

using namespace std;

int n,m,k,ans;
vector<vector<int>> board;
// 0상, 1우, 2둘다
vector<vector<int>> wall;
vector<vector<int>> blowers;
vector<pair<int,int>> toCheck;

// 우좌상하
// 시계방향순
int dx[4][3] = {
  {-1,0,1},
  {1,0,-1},
  {-1,-1,-1},
  {1,1,1}
};
int dy[4][3] = {
  {1,1,1},
  {-1,-1,-1},
  {-1,0,1},
  {1,0,-1}
};
// [dir][3갈래방향][2벽][x,y,상or우 방향]
int dwall[4][3][2][3] = {
    {{{0,0,0},{-1,0,1}},{{0,0,1}},{{1,0,0},{1,0,1}}},
    {{{1,0,0},{1,-1,1}},{{0,-1,1}},{{0,0,0},{-1,-1,1}}},
    {{{0,-1,1},{0,-1,0}},{{0,0,0}},{{0,0,1},{0,1,0}}},
    {{{0,0,1},{1,1,0}},{{1,0,0}},{{0,-1,1},{1,-1,0}}}
};

/* 
1. 집에 있는 모든 온풍기에서 바람이 한 번 나옴
2. 온도가 조절됨
3. 온도가 1 이상인 가장 바깥쪽 칸의 온도가 1씩 감소
4. 초콜릿을 하나 먹는다.
5. 조사하는 모든 칸의 온도가 K 이상이 되었는지 검사. 모든 칸의 온도가 K이상이면 테스트를 중단하고, 아니면 1부터 다시 시작한다. 
벽은 0이면 해당칸의 위, 1이면 오른쪽에 존재

0: 빈 칸
1: 방향이 오른쪽인 온풍기가 있음
2: 방향이 왼쪽인 온풍기가 있음
3: 방향이 위인 온풍기가 있음
4: 방향이 아래인 온풍기가 있음
5: 온도를 조사해야 하는 칸
*/

void blowAir(int x, int y, int dir, int cnt, vector<vector<int>> &tboard) {
  if (cnt <= 0) return;

  if (tboard[x][y] != cnt) tboard[x][y] = cnt;
  
  for (int i=0; i<3; i++) {
    int nx = x+dx[dir][i];
    int ny = y+dy[dir][i];

    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

    bool flag = true;
    for (int j=0; j<2; j++){

      // 가운데는 벽 1개
      if (i == 1 && j == 1) break;

      int dwx = dwall[dir][i][j][0];
      int dwy = dwall[dir][i][j][1];
      int wdir = dwall[dir][i][j][2];

      if (wall[x+dwx][y+dwy] == wdir || wall[x+dwx][y+dwy] == 2) flag = false;
    }

    if (flag) blowAir(nx, ny, dir, cnt-1, tboard);
  }
}

void addBoard(vector<vector<int>> tboard) {
  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++)
      board[i][j] += tboard[i][j];
}

void blow() {
  for (auto blower : blowers) {
    vector<vector<int>> tboard(n, vector<int> (m,0));
    int x = blower[0];
    int y = blower[1];
    int dir = blower[2];

    blowAir(x+dx[dir][1], y+dy[dir][1], dir, 5, tboard);
    addBoard(tboard);
  }
}

void print() {
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++)
      cout << board[i][j] << " ";
    cout << endl;
  }
  
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++)
      if (wall[i][j] >= 0)
        cout << i << " " << j << " " << wall[i][j] << endl;
  }
}

void adjustTemp() {
  // {iscol,idx,fr,to,diff}
  vector<vector<int>> moves;
  // col
  for (int i=0; i<m; i++)
    for (int j=1; j<n; j++){
      if (wall[j][i] == 0 || wall[j][i] == 2) continue;

      int diff = ceil((abs(board[j-1][i] - board[j][i]))/4);
      if (diff == 0) continue;

      if (board[j-1][i] > board[j][i]) moves.push_back({1,i,j-1,j,diff});
      else moves.push_back({1,i,j,j-1,diff});
    }
      
  // row
  for (int i=0; i<n; i++)
    for (int j=0; j<m-1; j++){
      if (wall[i][j] == 1 || wall[i][j] == 2) continue;

      int diff = ceil((abs(board[i][j] - board[i][j+1]))/4);
      if (diff == 0) continue;

      if (board[i][j] > board[i][j+1]) moves.push_back({0,i,j,j+1,diff});
      else moves.push_back({0,i,j+1,j,diff});
    }
  
  for (auto move : moves) {
    int iscol = move[0];
    int idx = move[1];
    int fr = move[2];
    int to = move[3];
    int diff = move[4];

    if (iscol) {
      board[fr][idx] -= diff;
      board[to][idx] += diff;
    } else {
      board[idx][fr] -= diff;
      board[idx][to] += diff;
    }
  }
}

void downTemp() {
  for (int i=0; i<n; i++) {
    if (board[i][0]) board[i][0]--;
  }
  for (int i=0; i<n; i++) {
    if (board[i][m-1]) board[i][m-1]--;
  }
  for (int i=1; i<m-1; i++) {
    if (board[0][i]) board[0][i]--;
  }
  for (int i=1; i<m-1; i++) {
    if (board[n-1][i]) board[n-1][i]--;
  }
}

void eatChoco() {
  ans++;
}

bool check() {
  if (ans > 100) return true;

  for (auto c : toCheck) {
    int x = c.first;
    int y = c.second;
    if (board[x][y] < k) return false;
  }
  return true;
}

int solution() {

  while(1) {
    blow();
    // cout << "after blow" << " " << ans << endl;
    // print();
    adjustTemp();
    // cout << "after adjustTemp" << " " << ans << endl;
    // print();
    downTemp();
    eatChoco();
    if (check()) {
      // print();
      return ans;
    }
  }
  return -1;
}

void test() {
  print();
  downTemp();
  print();
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m >> k;

  board.resize(n);
  wall.resize(n);
  for (int i=0; i<n; i++){
    board[i].resize(m);
    wall[i].resize(m);

    for (int j=0; j<m; j++) {
      int a;
      cin >> a;

      if (1<= a && a <= 4) blowers.push_back({i,j,a-1});
      if (a == 5) toCheck.push_back({i,j});
    }
  }

  fill(wall.begin(), wall.end(), vector<int> (m,-1));

  int w,x,y,t;

  cin >> w;
  for (int i=0; i<w; i++) {
    cin >> x >> y >> t;  
    if (wall[x-1][y-1] >= 0) wall[x-1][y-1] = 2;
    else wall[x-1][y-1] = t;
  }

  cout << solution();
}