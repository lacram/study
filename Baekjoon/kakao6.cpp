#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
  // 1공격 2방어
  //r1 < r2 , c1 < c2
  //[type, r1, c1, r2, c2, degree]

  for (int i=0; i<board.size(); i++){
    for (int j=0; j<board[i].size(); j++){
      for (auto s : skill){
        int type = s[0];
        int r1 = s[1], c1 = s[2] ,r2 = s[3], c2 = s[4];
        int degree = s[5];

        if (type == 1){
          if (r1 <= i && i <= r2 && c1 <= j && j <= c2) board[i][j] -= degree;
        }
        else{
          if (r1 <= i && i <= r2 && c1 <= j && j <= c2) board[i][j] += degree;
        }
      }
    }
  }
  int ans = 0;
  for (auto line : board)
    for (auto b : line)
      if (b > 0)
       ans++;
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");



  cout << solution({{1,2,3},{4,5,6},{7,8,9}},{{1,1,1,2,2,4},{1,0,0,1,1,2},{2,2,0,2,0,100}});
}