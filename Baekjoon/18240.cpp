#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
// 깊이별 자식수
int depth[300000];
int arr[300000];

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cin >> n;

  depth[0] = 1; 

  for (int i=0; i<n-1; i++){
    int t;
    cin >> t;

    if (depth[t-1] == 0) {
      cout << -1;
      break;
    }
    depth[t]++;
  }

}