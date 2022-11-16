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

map<string,int> m;
int visited[51];
vector<vector<int>> tree;
int targetNum;
int beginNum;

int bfs() {
  // 횟수, 매핑된 숫자
  queue<pair<int,int>> q;

  q.push({0,beginNum});

  while(!q.empty()) {
    int cnt = q.front().first;
    int num = q.front().second;

    q.pop();

    if (num == targetNum) return cnt;

    for (auto node : tree[num]) {
      if (visited[node]) continue;

      visited[node] = 1;
      q.push({cnt+1, node});
    }
  }

  return 0;
}

bool check(string w1, string w2) {
  int cnt = 0;
  for (int i=0; i<w1.size(); i++) {
    if (w1[i] != w2[i]) cnt++;
  }
  return cnt == 1;
}

int solution(string begin, string target, vector<string> words) {
  // string to int 매핑
  int idx = 0;
  words.push_back(begin);
  for (auto word : words) {
    if (word == begin) beginNum = idx;
    m[word] = idx++;
  }
  targetNum = m[target] = idx;

  // 변환가능한 단어 트리화
  tree.resize(words.size()+1);
  for (auto word: words) {
    for (auto cmp : words) {
      if (word == cmp) continue;

      if (check(word,cmp)) {
        tree[m[word]].push_back(m[cmp]);
      }
    }
  }

  return bfs();
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution("hit",	"cog",	{"hot", "dot", "dog", "lot", "log", "cog"});

}