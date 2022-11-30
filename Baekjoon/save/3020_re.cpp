#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,h;
int bot[100000];
int top[100000];

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> h;

  for (int i=0; i<n/2; i++){
    cin >> bot[i] >> top[i];
  }

  sort(bot,bot+n/2);
  sort(top,top+n/2);

  int ans = 200001;
  int num = 0;
  for (int height=1; height<=h; height++){
    int cnt = 0;

    int idx = lower_bound(bot,bot+n/2,height)-bot;
    cnt += n/2-idx;

    idx = upper_bound(top,top+n/2,h-height)-top;
    cnt += n/2-idx;

    if (ans == cnt) num++;
    if (ans > cnt){
      ans = cnt;
      num = 1;
    }
  }

  cout << ans << " " << num;
}