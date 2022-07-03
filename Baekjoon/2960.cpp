#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

int n, k;
int deleted[1001] = {0};

int solve(){

  for (int i=2; i<=n; i++){
    for (int j=i; j<=n; j+=i){
      if (!deleted[j]){
        deleted[j] = 1;
        k--;        
        if (k == 0)
          return j;
      }    
    }
  }
  return -1;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> k;

  cout << solve();
}