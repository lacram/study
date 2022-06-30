#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <map>
#define endl '\n'

using namespace std;

int m,k;
long long n;
map<pair<long long, int>, double> dp;

double solve(long long chip, int round){
  if (round == k){
    if (chip > 0) return 1;
    return 0;
  }

  pair<long long, int> p = make_pair(chip,round);

  if (dp.find(p) != dp.end())
    return (*dp.find(p)).second;

  double ret;
  int bigcnt = chip % m;
  long long big = chip/m+1;
  
  if (bigcnt == 0) ret = solve(chip-(chip/m),round+1);
  else ret = solve(chip-big, round+1) * bigcnt/m + solve(chip-big+1,round+1) * (m-bigcnt)/m;
  dp[p] = ret;

  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");
  cout.precision(4);

  cin >> n >> m >> k;

  cout << solve(n,0);

}