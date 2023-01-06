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
#define INF 2000000000

using namespace std;

int n;
int workTime[501];
int dp[501];
int record[501];
vector<vector<int>> tree(501);
vector<int> root;

void bfs() {
  queue<int> q;
  for (auto r : root) {
    q.push(r);
    dp[r] = workTime[r];
  }

  while (!q.empty()) {
    int now = q.front();
    q.pop();

    for (auto next : tree[now]) {

      dp[next] = max(dp[next], dp[now] + workTime[next]); 
      if (--record[next] == 0) q.push(next);
    }
  }
}

void solution() {
  bfs();

  for (int i=1; i<=n; i++) {
    cout << dp[i] << endl;
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=1; i<=n; i++){
    int a,b;
    cin >> a >> b;
    workTime[i] = a;
    if (b == -1) root.push_back(i);
    while (b != -1) {
      tree[b].push_back(i);
      cin >> b;
      record[i]++;
    }
  }

  solution();
}