#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#define endl '\n'

using namespace std;

string from = "";
string to = "123456780";
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

int bfs(){
  map<string,int> m;
  m[from] = 0;
  queue<string> q;
  q.push(from);

  while (!q.empty()){
    string now = q.front();
    q.pop();
    int cnt = m[now];

    if (now == to) return cnt;

    int idx = now.find("0");
    int x = idx / 3;
    int y = idx % 3;

    for (int i=0; i<4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || ny < 0 || nx > 2 || ny > 2) continue;
      
      int nidx = nx*3 + ny;
      swap(now[idx], now[nidx]);
      if (m.count(now) == 0) {
        q.push(now);
        m[now] = cnt+1;
      }
      swap(now[idx], now[nidx]);
    }
  }
  return -1;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  for (int i=0; i<9; i++){
    char a;
    cin >> a;
    from += a;
  }

  cout << bfs();
}