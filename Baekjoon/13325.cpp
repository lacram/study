#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
int arr[1<<21];
int ans = 0;

// 최대 가중치 리턴
int solve(int node){
  
  if (node >= 1<<n){
    ans += arr[node];
    return arr[node];
  }
  else{
    int left = solve(node*2);
    int right = solve(node*2+1);

    ans += arr[node] + abs(left-right);
    return max(left,right) + arr[node];
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  int size = 1<<(n+1);

  for (int i=2; i<size; i++){
    cin >> arr[i];
  } 

  solve(1);

  cout << ans;
}