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

int n, m, k;
int dest[101][101];
char board[101][101];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

/* 
0,0, 99,99
0 ~ 9999

 */

int solution() {
  
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  int test;
  cin >> test;

  for (int t=1; t<=test; t++) {
    cin >> n >> m >> k;

    memset(dest, 0, sizeof(dest));

    for (int i=0; i<n; i++)
      for (int j=0; j<m; j++) {
        cin >> board[i][j];
      }
    
    for (int i=0; i<k; i++) {
      int a,b;
      cin >> a >> b;
      dest[a-1][b-1] = 1;
    }

    cout << "#" << t << " " << solution() << endl;
  }
}