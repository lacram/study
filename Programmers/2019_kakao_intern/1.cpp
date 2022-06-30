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

stack<int> s[31];

int solution(vector<vector<int>> board, vector<int> moves) {
  int answer = 0;
  int n = board.size();
  
  // 스택에 1열씩 담음
  for (int i=n-1; i>=0; i--){
    for (int j=n-1; j>=0; j--){
      if (board[j][i] == 0) break;
      s[i].push(board[j][i]);
    }
  }

  stack<int> b;
  b.push(-1);
  int cnt = 0;

  for (int i=0; i<moves.size(); i++){
    int select = moves[i]-1;
    if (s[select].empty()) continue;

    int doll = s[select].top();
    s[select].pop();

    if (b.top() == doll) {
      b.pop();
      cnt++;
    }
    else {
      b.push(doll);
    }
  }
  
  return cnt*2;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  vector<vector<int>> b = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
  vector<int> m = {1,5,3,5,1,2,1,4};

  cout << solution(b,m);

}