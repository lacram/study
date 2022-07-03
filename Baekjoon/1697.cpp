#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#define endl '\n'

using namespace std;

int n,k;
int visited[100001];

int bfs(){
  queue<pair<int,int>> q;
  q.push({n,0});

  while (!q.empty()){
    int now = q.front().first;
    int time = q.front().second;
    q.pop();

    if (now == k) return time;
    if (now < 0 || now > 100000) continue;
    if (visited[now]) continue;

    visited[now] = 1;

    q.push({now*2,time+1});
    q.push({now+1,time+1});
    q.push({now-1,time+1});
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> k;

  cout << bfs();

}