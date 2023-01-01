#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;


int test, h, w, num,x,y;

int solve(int tox, int toy){
  int dp[tox+1][toy+1];
  memset(dp, 0, sizeof(dp));
  dp[0][1] = 1;

  for (int i=1; i<=tox; i++)
    for (int j=1; j<=toy; j++)
      dp[i][j] = dp[i-1][j] + dp[i][j-1];
  return dp[tox][toy];
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> h >> w >> num;
  num -= 1;
  x = num/w+1;
  y = num%w+1;

  if (num==-1) cout << solve(h,w);
  else cout << solve(x,y) * solve(h-x+1,w-y+1);

}