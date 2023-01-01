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
1. 가장자리가 검은 정사각형인지 판별
2. 해당비율에 적합한지 판별

 */

vector<string> board;

bool isRightSquare(int x, int y, int n) {
  for (int i=y; i<y+n; i++) {
    if (board[x][i] != '#') return false;
  }
  for (int i=y; i<y+n; i++) {
    if (board[x+n-1][i] != '#') return false;
  }
  for (int i=x; i<x+n; i++) {
    if (board[i][y] != '#') return false;
  }
  for (int i=x; i<x+n; i++) {
    if (board[i][y+n-1] != '#') return false;
  }
  return true;
}

bool isQRcode(int low, int high, int k, int n) {
  if (pow(n-2,2)*low > k*100) return false;
  if (pow(n-2,2)*high <= k*100) return false;
  return true;
}

int getK(int x, int y, int n) {
  int cnt = 0;
  for (int i=x; i<x+n; i++)
    for (int j=y; j<y+n; j++) {
      if (board[i][j] == '#') 
        cnt++;
    }
  return cnt;
}

int solution(int low, int high, vector<string> img) {
  board = img;
  int ans = 0;
  for (int i=0; i<img.size(); i++)
    for (int j=0; j<img[i].size(); j++) {
      int n = 2;
      while (i+n <= img.size() && j+n <= img[0].size()) {
        if (isRightSquare(i,j,n)) {
          int k = getK(i+1,j+1,n-2);
          if (isQRcode(low,high,k,n))
            ans++;
        }
        n++;
      }
    }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution(0,30,{"###", "#.#", "###"});

}