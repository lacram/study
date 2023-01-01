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
dp
 */

int solution(vector<vector<int>> board) {
  
  int ans = 0;
  for (int i=1; i<board.size(); i++)
    for (int j=1; j<board[i].size(); j++) {
      if (board[i][j]) {
        board[i][j] = min({board[i][j-1],board[i-1][j-1],board[i-1][j]}) + 1;
        ans = max(ans, board[i][j]);
      }
    }
  return ans*ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution({{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,1,0}});

}