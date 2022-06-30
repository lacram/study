#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
int arr[5000];
int ans[3];
long long ret=3000000001;

void solve(){
  sort(arr, arr+n);
  
  for (int i=0; i<n; i++)
    for (int j=i+1; j<n; j++){
      long long tmp = arr[i]+arr[j];
      int idx = lower_bound(arr,arr+n,tmp*(-1))-arr;
      if (idx <= j) idx = j+1;
      
      if (ret > abs(tmp+arr[idx]) && idx < n){
        ret = abs(tmp+arr[idx]);
        ans[0]=arr[i];
        ans[1]=arr[j];
        ans[2]=arr[idx];
      }
      if (ret > abs(tmp+arr[idx-1]) && idx-1 > j && idx-1 < n){
        ret = abs(tmp+arr[idx-1]);
        ans[0]=arr[i];
        ans[1]=arr[j];
        ans[2]=arr[idx-1];
      }
    }
  sort(ans,ans+3);

  for (int i=0; i<3; i++)
    cout << ans[i] << " ";
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

  solve();
  
}