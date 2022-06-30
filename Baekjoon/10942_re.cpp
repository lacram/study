#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,t;
int arr[2000];
int palindrome[2000][2000];

void solve(){
  for (int i=0; i<n; i++){
    // 홀수
    int gap = 0;
    while (i-gap >= 0 && i+gap < n && arr[i-gap] == arr[i+gap]){
      palindrome[i-gap][i+gap] = 1;
      gap++;
    }
    // 짝수
    gap = 1;
    while (i+1-gap >= 0 && i+gap < n && arr[i+1-gap] == arr[i+gap]){
      palindrome[i+1-gap][i+gap] = 1;
      gap++;
    }
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

  cin >> t;
  for (int i=0; i<t; i++){
    int a,b;
    cin >> a >> b;
    cout << palindrome[a-1][b-1] << endl; 
  }
}