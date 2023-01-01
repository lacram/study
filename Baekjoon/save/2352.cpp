#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
int arr[40000];
int lis[40000];

int solve(){
  int maxIdx = 0;
  lis[0] = arr[0];
  
  for (int i=1; i<n; i++){
    // 더 큰값 들어왔을때 길이 갱신
    if (lis[maxIdx] < arr[i]){
      maxIdx++;
      lis[maxIdx] = arr[i];
    }
    else {
      int a = lower_bound(lis, lis+maxIdx, arr[i]) - lis;
      lis[a] = arr[i];
    }
  }

  return maxIdx+1;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    cin >> arr[i];
  }

  cout << solve();
}