#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

int n;
int num[100];
int op[4];

int solve(int res, int pos){
  if (pos == n) return res;

  int ret = -1000000000;
  for (int i=0; i<4; i++){
    if (op[i]){
      op[i]--;
      if (i==0) ret = max(ret, solve(res+num[pos], pos+1));
      if (i==1) ret = max(ret, solve(res-num[pos], pos+1));
      if (i==2) ret = max(ret, solve(res*num[pos], pos+1));
      if (i==3) ret = max(ret, solve(res/num[pos], pos+1));
      op[i]++;
    }
  }
  return ret;
}
int solve2(int res, int pos){
  if (pos == n) return res;

  int ret = 1000000000;
  for (int i=0; i<4; i++){
    if (op[i]){
      op[i]--;
      if (i==0) ret = min(ret, solve2(res+num[pos], pos+1));
      if (i==1) ret = min(ret, solve2(res-num[pos], pos+1));
      if (i==2) ret = min(ret, solve2(res*num[pos], pos+1));
      if (i==3) ret = min(ret, solve2(res/num[pos], pos+1));
      op[i]++;
    }
  }
  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    cin >> num[i];
  }

  for (int i=0; i<4; i++){
    cin >> op[i];
  }

  cout << solve(num[0], 1);
  cout << endl;
  cout << solve2(num[0],1);
}