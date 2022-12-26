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

int n,k,want;
int record[1001];
int dp[1001];
int time[1001];
vector<vector<int>> tree;

/* 
트리로 만들기
루트 노드 찾기
bfs
 */

void bfs() {
  queue<int> q;
  for (int i=1; i<=n; i++)
    if (record[i] == 0)
      q.push(i);

  while (!q.empty()) {
    int now = q.front();
    q.pop();

    for (auto next : tree[now]) {
      dp[next] = max(dp[next], dp[now]+time[next]);

      // 중복 삽입 방지
      if (--record[next] == 0) q.push(next);
    }
  }
}

int solution() {
  for (int i=1; i<=n; i++) {
    dp[i] = time[i];
  }

  bfs();

  return dp[want];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  int test;
  cin >> test;
  while (test--) {

    cin >> n >> k;

    for (int i=1; i<=n; i++){
      cin >> time[i];
    }

    tree.clear();
    tree.resize(n+1);
    memset(dp, 0, sizeof(dp));
    memset(record, 0, sizeof(record));

    for (int i=0; i<k; i++) {
      int a,b;
      cin >> a >> b;
      tree[a].push_back(b);
      record[b]++;
    }
    cin >> want;

    cout << solution() << endl;
  }
}