#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,k;
int arr[505];
int dp[505][505];

// srt 부분수열 중 답이 최대인것 리턴
int solve(int srt, int cnt) {

  if (srt == n-1) return 1;

  int & ret = dp[srt][cnt];
  if (ret != -1) return ret;
  ret = 1;

  for (int i=srt+1; i<n; i++) {
    if (arr[srt] <= arr[i])
      ret = max(ret, solve(i,cnt)+1);
    if (arr[srt] > arr[i] && cnt > 0)
      ret = max(ret, solve(i,cnt-1)+1);
  }

  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> k;

  for (int i=0; i<n; i++){
    cin >> arr[i];
  }

  memset(dp, -1, sizeof(dp));

  cout << solve(0,k);
}