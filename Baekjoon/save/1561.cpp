#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,m;
int runningT[10000];

bool decision(long long time){
  long long cnt = 0;

  for (int i=0; i<m; i++){
    cnt += time/runningT[i] + 1;
  }

  return cnt >= n;
}

long long getTime(){
  long long lo = 0;
  long long hi = 60000000000;

  while (lo <= hi){
    long long mid = (lo+hi)/2;

    if (decision(mid)) hi = mid-1;
    else lo = mid+1;
  }
  
  return lo;
}

int solve(){
  long long finTime = getTime();
  int cnt = 0;

  if (finTime == 0) return n;

  for (int i=0; i<m; i++){
    cnt += (finTime-1)/runningT[i] + 1;
  }

  int num = n-cnt;

  for (int i=0; i<m; i++){
    if (finTime % runningT[i] == 0)
      num--;
    if (num == 0) return i+1;
  }
  // 에러
  return -1;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  for (int i=0; i<m; i++){
    cin >> runningT[i];
  }

  cout << solve();

}