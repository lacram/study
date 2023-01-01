#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#define endl '\n'

using namespace std;

int h,w,ans;
char board[102][102];
vector<pair<int,int>> needKey;
bool visited[102][102];
bool checkNeedKey[102][102];
bool hasKey[26];
// 오 아 왼 위
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool isDoor(int x, int y){
  if (board[x][y] >= 'A' && board[x][y] <= 'Z')
    return true;
  return false;
}

bool isKey(int x, int y){
  if (board[x][y] >= 'a' && board[x][y] <= 'z')
    return true;
  return false;
}

int bfs(){
  queue<pair<int,int>> q;

  q.push({0,0});
  visited[0][0] = 1;
  
  while (!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for (int i=0; i<4; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];

      if (nx > h+1 || nx < 0 || ny > w+1 || ny < 0) continue;
      if (board[nx][ny] == '*') continue;
      if (visited[nx][ny]) continue;
      
      // 문 발견시
      if (isDoor(nx,ny)){
        // 열쇠 없으면 필요한 열쇠에 추가
        if (!hasKey[board[nx][ny]-'A']) {
          needKey.push_back({nx,ny});
          continue;
        }
      }

      // 열쇠 발견
      if (isKey(nx,ny)){
        hasKey[board[nx][ny]-'a'] = 1;
        // 찾은 열쇠로 갈 수 있는곳이 있으면 큐에 추가
        for (auto p : needKey){
          int a = p.first;
          int b = p.second;
          if (!visited[a][b] && hasKey[board[a][b]-'A']){
            visited[a][b] = 1;
            q.push({a,b});
          }
        }
      }
      // 문서 발견
      if (board[nx][ny] == '$') {
        ans++;
      }
      q.push({nx,ny});
      visited[nx][ny] = 1;
    }
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  int test;
  cin >> test;

  while(test--){

    cin >> h >> w;

    for (int i=1; i<=h; i++)
      for (int j=1; j<=w; j++)
        cin >> board[i][j];
    
    for (int i=0; i<=h+1; i++){
      board[i][0] = '.';
      board[i][w+1] = '.';
    }

    for (int i=0; i<=w+1; i++){
      board[0][i] = '.';
      board[h+1][i] = '.';
    }
      
    needKey.clear();
    memset(visited, false, sizeof(visited));
    memset(checkNeedKey, false, sizeof(checkNeedKey));
    memset(hasKey, false, sizeof(hasKey));
    ans = 0;

    string key;
    cin >> key;

    if (key != "0")
      for (int i=0; i<key.length(); i++)
        hasKey[key[i]-'a'] = 1;

    cout << bfs() << endl;
  }
}