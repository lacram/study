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
int capacity[60][60], flow[60][60], sum = 0;
vector<int> line[60];

int maxFlow(int source, int sink) {
  while(1) {
    int parent[60] = {};
    queue<int> q;
    q.push(source);

    while(!q.empty()) {
      int cur = q.front();
      q.pop();
      for(int i=0; i<line[cur].size(); i++) {
        int next = line[cur][i];
        if(capacity[cur][next] - flow[cur][next] > 0 && !parent[next]) {
          q.push(next);
          parent[next] = cur;
          if(next == sink) break;
        }
      }
    }

    if(!parent[sink]) break;

    int amount = INF;
    for(int i=sink; i!=source; i=parent[i])
      amount = min(amount, capacity[parent[i]][i] - flow[parent[i]][i]);
    for(int i=sink; i!=source; i=parent[i]) {
      flow[parent[i]][i] += amount;
      flow[i][parent[i]] -= amount;
    }
    sum += amount;
  }
  return sum;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    char a,b;
    int c;
    cin >> a >> b >> c;
    // A = 65
    int x = int(a)-64;
    int y = int(b)-64;
    capacity[x][y] += c;
    capacity[y][x] += c;
    line[x].push_back(y);
    line[y].push_back(x);
  }

  cout << maxFlow(1,26);
}