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

int ans;
int visited[8];
vector<vector<int>> dungeons;

void dfs(int health, int depth) {
  ans = max(ans, depth);

  for (int next=0; next<dungeons.size(); next++) {
    if (visited[next]) continue;
    if (health < dungeons[next][0]) continue;

    visited[next] = 1;
    dfs(health-dungeons[next][1], depth+1);
    visited[next] = 0;
  }
}

int solution(int k, vector<vector<int>> d) {
  dungeons = d;

  dfs(k,0);

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution(80, {{80, 20}, {50, 40}, {30, 10}});

}