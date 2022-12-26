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

int n, m;
int board[1025][1025];
int psum[1025][1025];

void setPrefixSum() {
  // 행 업데이트
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++)
      psum[i][j] += psum[i][j-1] + board[i][j];
  }
  // 열 업데이트
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++)
      psum[j][i] += psum[j-1][i];
  }
}

int solution(int x1, int y1, int x2, int y2) {
  return psum[x2][y2] - psum[x1-1][y2] - psum[x2][y1-1] + psum[x1-1][y1-1];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  for (int i=1; i<=n; i++){
    for (int j=1; j<=n; j++)
      cin >> board[i][j];
  }

  setPrefixSum();

  for (int i=0; i<m; i++) {
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    cout << solution(x1,y1,x2,y2) << endl;
  }

}