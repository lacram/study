#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,m;
int arr[2000];
int dp[2000][2000] = {0};

void solve(){
  for (int i=0; i<n; i++){
    dp[i][i] = 1;

    int t = 1;
    // 펠린드롬이 홀수
    while (i-t >=0 && i+t < n){
      if (arr[i-t] == arr[i+t]){
        dp[i-t][i+t] = 1;
        t++;
      }
      else break;
    }
    t = 1;
    // 펠린드롬이 짝수
    while (i-t >=0 && i+t-1 < n){
      if (arr[i-t] == arr[i+t-1]){
        dp[i-t][i+t-1] = 1;
        t++;
      }
      else break;
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

  cin >> m;

  solve();

  for (int i=0; i<m; i++){
    int a,b;
    cin >> a >> b;
    a-=1;
    b-=1;

    cout << dp[a][b] << endl;
  }
}