#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define endl '\n'
#define INF 2000000000

using namespace std;

vector<string> board;
set<pair<int,int>> toDelete;
int h,w;
int ans = 0;

bool find(int x, int y) {
  char target = board[x][y];
  if (target == 'x') return false;

  if (board[x][y+1] == target && board[x+1][y] == target && board[x+1][y+1] == target){
    toDelete.insert({x,y});
    toDelete.insert({x+1,y});
    toDelete.insert({x,y+1});
    toDelete.insert({x+1,y+1});
    return true;
  }
  return false;
}

void del(){
  for (auto it=toDelete.begin(); it!=toDelete.end(); it++){
    board[(*it).first][(*it).second] = 'x';
  }

  for (int i=w-1; i>=0; i--)
    for (int j=h-1; j>=0; j--) {
      int bf = j;
      while (j > 0 && board[j][i] == 'x'){
        j--;
      }
      if (board[j][i] != 'x') swap(board[j][i], board[bf][i]);
      j = bf;
    }
  ans += toDelete.size();
  toDelete.clear();
}

int solution(int m, int n, vector<string> b) {
  board = b;
  h = m;
  w = n;

  while (1){
    bool tf = false;
    for (int i=0; i<m-1; i++){
      for (int j=0; j<n-1; j++){
        tf |= find(i,j);
      }
    }
    if (!tf) break;
    del();
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution(6  ,     6 ,      {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"});

}