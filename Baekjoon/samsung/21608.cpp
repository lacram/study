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

int n;
int like[401][4];
int board[21][21];
// {좋아하는 학생 수, 비어있는 칸 수, 행 번호, 열 번호}
vector<vector<int>> preferences;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<int> order;

/* 
1. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
2. 1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
3. 2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.
 */

vector<int> getPreference(int person, int x, int y) {
  vector<int> preference = {0,0,x,y};

  for (int i=0; i<4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

    for (int j=0; j<4; j++) {
      if (like[person][j] == board[nx][ny]) preference[0]++;
    }
    if (board[nx][ny] == 0) preference[1]++;
  }
  return preference;
}

bool cmp(vector<int> a, vector<int> b){
  if (a[0] == b[0]) {
    if (a[1] == b[1]) {
      if (a[2] == b[2]) {
        return a[3] < b[3];
      }
      return a[2] < b[2];
    }
    return a[1] > b[1];
  }
  return a[0] > b[0];
}

void getBestSeat(int person) {
  preferences.clear();

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) {
      if (board[i][j]) continue;

      preferences.push_back(getPreference(person,i,j));
    }
  
  sort(preferences.begin(), preferences.end(), cmp);

  int x = preferences[0][2];
  int y = preferences[0][3];

  board[x][y] = person;
}

int getScore(int x, int y) {
  int person = board[x][y];
  int cnt = 0;

  for (int i=0; i<4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    
    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

    for (int j=0; j<4; j++) {
      if (like[person][j] == board[nx][ny]) cnt++;
    }
  }

  if (cnt == 0) return cnt;
  return pow(10,cnt-1);
}

int solution() {

  for (auto person : order) {
    getBestSeat(person);
  }

  int ans = 0;
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      ans += getScore(i,j);
  
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n*n; i++){
    int a;
    cin >> a;
    order.push_back(a);
    for (int j=0; j<4; j++){
      cin >> like[a][j];
    }
  }

  cout << solution(); 
}