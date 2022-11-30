#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
int weight[300000];
int sorting[30];
int pos[30];

string str;

int solve(){
  int ans = 0;
  int t = n-1;

  while(t >= 0){

    int idx = pos[sorting[t]];
    if (weight[idx] == 0){
      t--;
      continue;
    }

    char c =  str[idx];
    
    int lo = idx-1, hi = idx+1;
    while (str[lo] == c || str[lo] == 'a') {
      lo--;
    }
    if (lo < 0) {
      t--;
      continue;
    }

    while (str[hi] == c || str[hi] == 'a') {
      hi++;
    } 
    if (hi >= n) {
      t--;
      continue;
    }

    for (int i=lo+1; i<=idx-1; i++) {
      str[i] = 'a';
      weight[i] = 0;
    }
    for (int i=idx+1; i<=hi-1; i++) {
      str[i] = 'a';
      weight[i] = 0;
    }

    str[idx] = 'a';
    ans += weight[idx];
    weight[idx] = 0;
    t--;
  }
  
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cin >> n;
  cin >> str;

  for (int i=0; i<n; i++){
    cin >> weight[i];
    sorting[i] = weight[i];
    pos[weight[i]] = i;
  }

  sort(sorting, sorting+n);

  cout << solve();
}