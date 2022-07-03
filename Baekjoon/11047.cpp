#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

int n, want;
int money[10];

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> want;

  for (int i=0; i<n; i++){
    cin >> money[i];
  }

  int ans=0;

  for (int i=n-1; i>=0; i--){
    if (money[i] > want) continue;
    ans += want / money[i];
    want = want % money[i];
  }

  cout << ans;
}