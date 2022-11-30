#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
int arr[1000000];
int cntLen[1000000];

void solve(){

  for (int i=n-2; i>=0; i--){
    int a = i;
    int b = n-1;
    int len = 0;

    while (arr[a] == arr[b]){
      a--;
      b--;
      len++;
    }

    cntLen[len]++;
  }
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

  bool check = false;

  for (int i=n-1; i>=1; i--){
    if (cntLen[i]){
      cout << i << " " << cntLen[i];
      check = true;
      break;
    }
  }

  if (!check) cout << -1;

}