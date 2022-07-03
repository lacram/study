#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
int weight[1000];

// idx번까지 무게를 측정 할 수 있었다면
// Σ weight[0~idx] 까지 측정 가능
// 0~idx-1의 추들로 weight[idx]-1까지 측정가능했기에 idx에 접근할 수 있었음
int solve(){
  sort(weight, weight+n);

  int cant = 1;
  for (int i=0; i<n; i++){
    if (weight[i] <= cant) cant += weight[i];
    else break;
  }

  return cant;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    cin >> weight[i];
  }

  cout << solve();
}