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

int solution(vector<vector<int>> board, vector<int> moves) {
  int n = board.size();
  stack<int> line[30];
  stack<int> out;

  // 열 별로 스택에 쌓기
  for (int i=n-1; i>=0; i--)
    for (int j=0; j<n; j++) 
      if (board[i][j])
        line[j].push(board[i][j]);
  
  int ans = 0;

  for (auto move : moves) {
    move--;
    if (line[move].empty()) continue;

    int num = line[move].top();
    line[move].pop();

    // 터트릴 수 있을 경우
    if (!out.empty() && out.top() == num) {
      out.pop();
      ans++;
    }
    else {
      out.push(num);
    }
  }

  return ans*2;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}