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
int ans;
int board[20][20];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int visited[20][20];
vector<int> group;

// 총 블록 수 , 무지개 블록 수 , 행 , 열
void findGroup(int x, int y, int now) {
  visited[x][y] = 1;
  group[0]++;

  // 무지개 블록
  if (board[x][y] == 0) group[1]++;
  // 기준 블록은 x,y가 작은 좌표
  else {
    if (x < group[2] || (x == group[2] && y < group[3])) {
      group[2] = x;
      group[3] = y;
    }
  }

  for (int i=0; i<4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;  
    if (visited[nx][ny]) continue; 

    if (board[nx][ny] == now || board[nx][ny] == 0) {
      findGroup(nx,ny,now);
    }
  }
}

void print() {
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      if (board[i][j] == -2) cout << "_ "; 
      else if (board[i][j] == -1) cout << "9 "; 
      else cout << board[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

vector<int> findBigGroup() {
  vector<vector<int>> groups = {};

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) {
      int now = board[i][j];
      // 기본블록으로 시작해야함
      if (now <= 0) continue;

      memset(visited, 0, sizeof(visited));
      group = {0,0,i,j};
      findGroup(i,j,now);

      groups.push_back(group);
    }
  
  sort(groups.begin(), groups.end(), greater<>());

  // 블록 개수 2이상
  if (groups.empty() || groups[0][0] <= 1) return {};
  return groups[0];
}

void deleteGroup(int x, int y, int now) {

  board[x][y] = -2;
  
  for (int i=0; i<4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;   

    if (board[nx][ny] == now || board[nx][ny] == 0) {
      deleteGroup(nx,ny,now);
    }
  }
}

void moveDown(int x, int y) {
  // 벽에 닿음
  if (x+1 >= n) return;
  // 아래에 블록이 있음
  if (board[x+1][y] >= -1) return;

  // 블록 or 벽에 도달
  int nx = x+2;
  while (nx < n && board[nx][y] == -2){
    nx++;
  }

  board[nx-1][y] = board[x][y];
  board[x][y] = -2;
}

// 아래에서 위, 좌에서 우
void gravity() {
  for (int i=0; i<n; i++)
    for (int j=n-1; j>=0; j--) {
      if (board[j][i] >= 0) {
        moveDown(j,i);
      }
    }
}

void rotate() {
  int tmp[20][20] = {{0}};
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) {
      int x = n-1-j;
      int y = i;

      tmp[x][y] = board[i][j];
    }

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      board[i][j] = tmp[i][j];
  
}



int solution() {
  // auto play
  while(1) {
    vector<int> bigGroup = findBigGroup();
    if (bigGroup.empty()) return ans;
    deleteGroup(bigGroup[2],bigGroup[3], board[bigGroup[2]][bigGroup[3]]);
    ans += bigGroup[0]*bigGroup[0];
    gravity();
    rotate();
    gravity();
  }

  return -1;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++) {
      cin >> board[i][j];
    }
  }

  cout << solution();
}