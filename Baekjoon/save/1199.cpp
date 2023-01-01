#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
int adj[1010][1010];
int srt[1010];
vector<int> ans;

void getEulerCircuit(int now){
  
  for (int& next=srt[now]; next<=n; next++){
    while (adj[now][next]) {
      adj[now][next]--;
      adj[next][now]--;
      getEulerCircuit(next);
    }
  }
  ans.push_back(now);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  // 간선의 개수
  int cnt = 0;
  for (int i=1; i<=n; i++){
    for (int j=1; j<=n; j++){
      cin >> adj[i][j];
      cnt += adj[i][j];
    }
  }
  for (int i=1; i<=n; i++)
    srt[i] = 1;

  getEulerCircuit(1);
  
  // 간선 +1개, 시작 도착이 같아야함
  if (cnt/2 + 1 == ans.size() && ans.front() == ans.back())
    for (auto a: ans)
      cout << a << " ";
  else cout << -1;
}