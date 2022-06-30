#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,h;
int bottom[100000];
int top[100000];

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> h;

  for (int i=0; i<n/2; i++){
    cin >> bottom[i];
    int t;
    cin >> t;
    top[i] = h-t;
  }

  sort(bottom, bottom+n/2);
  sort(top, top+n/2); 

  int ret = 200000;
  int ans = 0;
  for (int height=1; height<=h; height++){
    int cnt = 0;
    // height <= bottom[idx]일때 부숨
    int idx = lower_bound(bottom,bottom+n/2,height)-bottom;
    cnt += n/2 - idx;

    // height > top[idx]일때 부숨
    idx = lower_bound(top,top+n/2,height)-top;
    cnt += idx;

    if (ret > cnt){
      ret = cnt;
      ans = 1;
    }
    else if (ret == cnt) ans++;
  }

  cout << ret << " " << ans;
}