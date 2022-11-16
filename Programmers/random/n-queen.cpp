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

int col[12];
int row[12];
int leftDiag[23];
int rightDiag[23];
int ans;
int n;

bool canPut(int x, int y) {
  if (col[y]) return false;
  if (row[x]) return false;
  if (leftDiag[x+y]) return false;
  if (rightDiag[n-1-y+x]) return false;
  return true;
}

void put(int x, int y) {
  col[y] = 1;
  row[x] = 1;
  leftDiag[x+y] = 1;
  rightDiag[n-1-y+x] = 1;
}

void take(int x, int y) {
  col[y] = 0;
  row[x] = 0;
  leftDiag[x+y] = 0;
  rightDiag[n-1-y+x] = 0;
}

void dfs(int row) {
  if (row == n) {
    ans++;
    return;
  }

  for (int col=0; col<n; col++) {
    if (canPut(row,col)) {
      put(row,col);
      dfs(row+1);
      take(row,col);
    }
  }
}

int solution(int m) {
  n = m;
  dfs(0);

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