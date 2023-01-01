#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int c,h,w;
char board[10][10];
int memo[10][1024][1024];

int solve(int hi, int now, int used, int usedN){
  if (hi == h) return 0;

  int& ret = memo[hi][used][usedN];
  if (ret != -1) return ret;
  ret = 0;

  for (int i=now; i<w; i++){
    if (i+1 < w && used & (1<<(i+1))) continue;
    if (i-1 >= 0 && used & (1<<(i-1))) continue;
    if (board[hi][i] == 'x') continue;
    ret = max(ret, solve(hi, i+2, used, usedN | (1<<i))+1);
  }
  ret = max(ret, solve(hi+1, 0, usedN, 0));

  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> c;

  while (c--){

    cin >> h >> w;

    for (int i=0; i<h; i++)
      for (int j=0; j<w; j++)
        cin >> board[i][j];

    memset(memo, -1 ,sizeof(memo));

    cout << solve(0,0,0,0) << endl;
  }

}