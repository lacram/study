#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <map>
#define endl '\n'

using namespace std;

int n,test;
int want[100001];
int visited[100001];
int pos[100001];
int ans;

void dfs(int now, int depth){
  if (visited[now]) return;

  visited[now] = 1;

  if (want[now] == now) {
    ans--;
    return;
  } 
  // 사이클 완성
  if (pos[want[now]]){
    ans -= depth - pos[want[now]] + 1;
    return;
  }
  // 미완성
  else {
    pos[now] = depth;
    dfs(want[now],depth+1);
    pos[now] = 0;
  }

}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> test;

  while (test--){
    
    cin >> n;

    for (int i=1; i<=n; i++){
      cin >> want[i];
    }

    memset(visited, 0, sizeof(visited));
    memset(pos, 0, sizeof(pos));
    ans = n;

    for (int i=1; i<=n; i++){
      dfs(i,1);
    }

    cout << ans << endl;
  }
}