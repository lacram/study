#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int arr[100000];

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

  int lo = 0;
  int hi = n-1;
  int ret = 2000000001;
  int x,y;

  while (lo < hi){
    int tmp = arr[lo]+arr[hi];
    if(abs(tmp) < ret){
      x = arr[lo];
      y = arr[hi];
      ret = abs(tmp);
    }
    if(tmp > 0) hi--;
    else lo++;
  }

  cout << x << " " << y;
}