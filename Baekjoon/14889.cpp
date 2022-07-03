#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int arr[20][20];
int used[20] = {1};
int ans=10000000;

void getSum(){
  int a = 0,b=0;
  for (int i=0; i<n; i++)
    for (int j=i+1; j<n; j++){
      if(used[i] == 1 && used[j] == 1){
        a+= arr[i][j];
        a+= arr[j][i];
      }
      if(used[i] == 0 && used[j] == 0){
        b+= arr[i][j];
        b+= arr[j][i];
      }
    }
  ans = min(ans, abs(a-b));
}

void solve(int srt, int depth){
  if (depth == n/2) {
    getSum();
  }

  for (int i=srt; i<n; i++){
    if (!used[i]){
      used[i] = 1;
      solve(i+1, depth+1);
      used[i] = 0;
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

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      cin >> arr[i][j];
  
  solve(1,1);
  cout << ans;

  

}