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

int visited[8];
vector<vector<int>> dungeons;
int ans;

void dfs(int health, int depth) {
  ans = max(ans, depth);

  for (int i=0; i<dungeons.size(); i++) {
    if (visited[i]) continue;  
    if (health < dungeons[i][0]) continue;

    visited[i] = 1;
    dfs(health-dungeons[i][1], depth+1);
    visited[i] = 0;
  }
}

int solution(int k, vector<vector<int>> d) {
  dungeons = d;

  dfs(k, 0);

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution(80, {{80,20},{50,40},{30,10}});

}