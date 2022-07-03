#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,s,m;
int volume[100];
int memo[100][1000];

int solve(int idx, int val){
  if ((val > m) || (val < 0)){
    return -10;
  }

  if (idx == n) {
    return val;
  }

  int &ret = memo[idx][val];

  if (ret != -1) return ret;

  return ret = max(solve(idx+1, val+volume[idx]), solve(idx+1, val-volume[idx]));
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> s >> m;

  for (int i=0; i<n; i++){
    cin >> volume[i];
  }

  memset(memo, -1, sizeof(memo));

  int ans = solve(0, s);

  if (ans == -10) cout << -1;
  else cout << ans;
}