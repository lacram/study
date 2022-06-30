#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int test, n,m;
int a[100];
int b[100];
int dp[101][101];
long long INF = -1000000000000000;

// a[x], b[y]이후부터 최대 jlis
int solve(int x, int y){

  int& ret = dp[x+1][y+1];
  if (ret != -1) return ret;
  ret = 0;

  long long lastA = x == -1 ? INF : a[x];
  long long lastB = y == -1 ? INF : b[y];

  long long last = max(lastA,lastB);

  for (int i=x+1; i<n; i++)
    if (last < a[i])
      ret = max(ret, solve(i,y)+1);
  
  for (int i=y+1; i<m; i++)
    if (last < b[i])
      ret = max(ret, solve(x,i)+1);

  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> test;
  while(test--){
    cin >> n >> m;
    
    for (int i=0; i<n; i++)
      cin >> a[i];
    
    for (int i=0; i<m; i++)
      cin >> b[i];
    
    memset(dp,-1,sizeof(dp));
    cout << solve(-1,-1) << endl;
  }
}