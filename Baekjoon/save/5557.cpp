#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
int arr[100];
long long memo[100][21];

// int solve(int idx, int val) : idx까지 합이 val인 식의 개수

// solve(9,8) = solve(8,0) + solve(8,16)

long long solve(int idx, int val){
  if (val < 0 || val > 20) return 0;

  if (idx == 0) {
    if (val == arr[idx]) return 1;
    return 0;
  }

  long long &ret = memo[idx][val];

  if (ret != -1) return ret;

  return ret = solve(idx-1, val-arr[idx]) + solve(idx-1, val+arr[idx]);
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

  memset(memo, -1 ,sizeof(memo));

  cout << solve(n-2, arr[n-1]);
}