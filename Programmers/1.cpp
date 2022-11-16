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

/* 
열을 기준으로 비트마스킹 -> board[10][1024]로 저장 가능
열 뒤집기 ~n
행 뒤집기 n = n ^ (1<<i)
 */

vector<int> state;
vector<int> destination;

int getBitNum(vector<int> v) {
  int ans = 0;
  for (int i=0; i<v.size(); i++) {
    ans += v[i] * (1<<i);
  }
  return ans;
}

bool checkFin(vector<int> now) {
  for (int i=0; i<now.size(); i++) {
    if (now[i] != destination[i]) return false;
  }
  return true;
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
  int n = beginning.size();

  for (auto v : beginning) {
    state.push_back(getBitNum(v));
  }
  for (auto v : target) {
    destination.push_back(getBitNum(v));
  }

  // cnt, 상태
  queue<pair<int,vector<int>>> q;
  q.push({0,state});

  while (!q.empty()) {
    int cnt = q.front().first;
    vector<int> now = q.front().second;
    q.pop();

    if (checkFin(now)) {
      return cnt;
    }

    // 열 뒤집기
    for (int i=0; i<n; i++) {
      int row = now[i];
      now[i] = ~row;
      q.push({cnt+1, now});
      now[i] = row;
    }

    // 행 뒤집기
    for (int i=0; i<n; i++) {
      vector<int> col;
      for (int j=0; j<n; j++) {
        col.push_back(now[j]);
        now[j] = now[j] ^ (1<<i);
      }
      q.push({cnt+1, now});
      for (int j=0; j<n; j++) {
        now[j] = col[j];
      }
    }
  }
  return -1;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}