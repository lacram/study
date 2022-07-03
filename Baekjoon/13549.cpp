#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#define endl '\n'

using namespace std;

int srt,fin;
int visited[100001];

int bfs(){
  queue<pair<int,int>> q;
  q.push({srt,0});

  while (!q.empty()){
    int pos = q.front().first;
    int time = q.front().second;
    q.pop();

    if (pos == fin) return time;

    if (pos*2 <= 100000 && visited[pos*2] > time) {
      q.push({pos*2, time});
      visited[pos*2] = time;
    }
    if (pos-1 >= 0 && visited[pos-1] > time+1) {
      q.push({pos-1,time+1});
      visited[pos-1] = time+1;
    }
    if (pos+1 <= 100000 && visited[pos+1] > time+1) {
      q.push({pos+1,time+1});
      visited[pos+1] = time+1;
    }

  }
  return -1;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> srt >> fin;

  for (int i=0; i<=100000; i++)
    visited[i] = 100000000;

  cout << bfs();

}