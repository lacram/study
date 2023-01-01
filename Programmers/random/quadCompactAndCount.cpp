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
현재 범위의 정사각형을 압축, 실패시 4등분해 반복 
dfs
 */

vector<vector<int>> board;
vector<int> ans(2);

pair<int,int> getCountPair(int x, int y, int n) {
  int zero = 0;
  int one = 0;
  for (int i=x; i<x+n; i++)
    for (int j=y; j<y+n; j++) {
      if (board[i][j]) one++;
      else zero++;
    }
  return {zero,one};
}

void dfs(int x, int y, int n) {

  pair<int,int> count = getCountPair(x,y,n);
  if (n == 1 || count.first == 0 || count.second == 0) {
    if (count.first == 0) ans[1]++; 
    if (count.second == 0) ans[0]++; 
    return;
  }

  dfs(x,y,n/2);
  dfs(x+n/2,y,n/2);
  dfs(x,y+n/2,n/2);
  dfs(x+n/2,y+n/2,n/2);
}

vector<int> solution(vector<vector<int>> arr) {
  board = arr;

  dfs(0,0,arr.size());
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution({{1,1,0,0},{1,0,0,0},{1,0,0,1},{1,1,1,1}} );

}