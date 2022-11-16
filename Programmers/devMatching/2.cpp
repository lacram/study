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

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

/* 
1. 구역별로 나누면서 구역별 나라 수 세기
2. 전쟁
 */

// {나라이름-'A', 영토 넓이}
vector<vector<int>> arr;
char maps[1001][1001];
int visited[1001][1001];
int total[26];
int n,m;

// 위치(x,y) , 구역
void dfs(int x, int y, int part) {

  arr[part][maps[x][y]-'A']++;
  visited[x][y] = 1;
  
  for (int i=0; i<4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (maps[nx][ny] == '.') continue;
    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
    if (visited[nx][ny]) continue;

    dfs(nx,ny,part);
  }
}

int solution(vector<string> map) {
  for (int i=0; i<map.size(); i++)
    for (int j=0; j<map[i].size(); j++)
      maps[i][j] = map[i][j];

  n = map.size();
  m = map[0].size();
  int p = 0;
  arr.resize(100000);
  for (int i=0; i<arr.size(); i++) {
    arr[i].resize(26);
  }

  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++) {
      if (visited[i][j]) continue;
      if (maps[i][j] == '.') continue;

      dfs(i,j,p++);
    }

  for (auto part : arr) {
    int maxSize = 0;
    // 먹힐 나라넓이
    int cnt = 0;
    // {나라,넓이}
    vector<pair<int,int>> maxGroup;

    for (int i=0; i<part.size(); i++) {
      int size = part[i];

      if (size == 0) continue;

      if (maxSize <= size) {
        if (maxSize < size) {
          cnt += maxSize * maxGroup.size();
          maxGroup.clear();
          maxSize = size;
        }
        maxGroup.push_back({i,size});
      } else {
        cnt += size;
      }
    }

    sort(maxGroup.begin(), maxGroup.end());

    for (int i=0; i<maxGroup.size(); i++) {
      int country = maxGroup[i].first;
      int size = maxGroup[i].second;

      total[country] += size;
      if (i == maxGroup.size()-1) total[country] += cnt;
    }
  }

  int ans = 0;
  for (int i=0; i<26; i++) {
    ans = max(ans, total[i]);
  }

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution({"XY..", "YX..", "..YX", ".AXY"});

}