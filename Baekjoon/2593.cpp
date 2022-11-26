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
#define INF 10000000

using namespace std;

int n,m;
int dp[100][100];
int back[100][100];
vector<vector<int>> arr;

vector<int> getFloors(int fr, int t, int n) {
  vector<int> v;
  for (int i=fr; i<=n; i+=t) {
    v.push_back(i);
  }
  return v;
}

// now = fr2 + k2 * t
bool canGo(vector<int> v1, vector<int> v2) {
  int fr = v1[0];
  int k = v1[1];
  int fr2 = v2[0];
  int k2 = v2[1];
  int now = fr - fr2;

  while (now <= n) {
    if (now >=0 && now % k2 == 0) return true;
    now += k;
  }
  return false;
}

void setDP() {
  for (int i=0; i<arr.size(); i++)
    for (int j=i+1; j<arr.size(); j++) {
      if (canGo(arr[i], arr[j])) {
        dp[i][j] = 1;
        dp[j][i] = 1;
      }
    }
}

void print(int fr, int to) {
  if (back[fr][to] != -1) {
    print(fr,back[fr][to]);
    cout << back[fr][to] << endl;
  }
}

int getIdx(int floor) {
  for (int i=0; i<arr.size(); i++) {
    int fr = arr[i][0];
    int k = arr[i][1];

    if (floor >= fr && (floor-fr) % k == 0) return i;
  }
  return -1;
}

void solution(int fr, int to) {
  for (int i=0; i<100; i++)
    for (int j=0; j<100; j++) {
      dp[i][j] = INF;
      back[i][j] = -1;
    }

  setDP();

  for (int k=0; k<m; k++)
    for (int i=0; i<m; i++)
      for (int j=0; j<m; j++) {
        if (dp[i][j] > dp[i][k] + dp[k][j]) {
          dp[i][j] = dp[i][k] + dp[k][j];
          back[i][j] = k;
        }
      }
  
  if (dp[fr][to] == INF) {
    cout << -1;
    return;
  }
  cout << dp[fr][to]+1 << endl;
  cout << fr+1 << endl;
  print(fr,to);
  cout << to+1 << endl;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cin >> n >> m;

  for (int i=0; i<m; i++){
    int fr, t;
    cin >> fr >> t;
    arr.push_back({fr,t});
  }

  int fr,to;
  cin >> fr >> to;

  if (getIdx(fr) == -1 || getIdx(to) == -1) {
    cout << -1;
    return 0;
  }
  solution(getIdx(fr), getIdx(to));
}