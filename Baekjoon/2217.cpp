#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

int n;
int rope[100000];
int total[100000];

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    cin >> rope[i];
  }

  sort(rope, rope+n);

  int ans = 0;
  for (int i=0; i<n; i++){
    total[i] = rope[i]*(n-i);
    ans = max(ans, total[i]);
  }

  cout << ans;
}