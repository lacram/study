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

/* 
삼각형 기준으로 dfs
 */

vector<int> board(510000);

// 시작점을 기준으로 세면을 채움
void fillTriangle(int start, int number, int n, int depth) {
  if (n <= 0) return;

  int now = start;
  // 좌
  for (int i=0; i<n; i++) {
    now = now+i + 2*depth;  
    board[now] = number++;
  }
  // 하
  for (int i=0; i<n-1; i++) {
    now++;
    board[now] = number++;
  }
  // 우
  for (int i=0; i<n-2; i++) {
    now = now - (n-i) - 2*depth;
    board[now] = number++;
  }
  fillTriangle(now, number, n-3, depth+1);
}

vector<int> solution(int n) {
  fillTriangle(0,1,n,0);
  int cnt = (n*(n+1))/2;

  vector<int> ans(board.begin(), board.begin()+cnt);
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution(4);

}