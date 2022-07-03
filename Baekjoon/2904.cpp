#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int prime[1000000] = {0};
int arr[100];

int gcd(int x, int y){
  if (y==0) return x;
  return gcd(y, x%y);
}

void getPrime(int t){
  int x = sqrt(t);
  for (int i=2; i<=x; i++){
    while (t % i == 0){
      t = t/i;
      prime[i] += 1;
    }
  }
  prime[t]++;
}

int solve(int t){
  int cnt = 0;
  int x = sqrt(t);
  for (int i=2; i<=x; i++){
    while (t % i == 0){
      t = t/i;
      cnt++;
    }
  }
  if (t>1) cnt++;
  return cnt;
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
    getPrime(arr[i]);
  }

  int ans = 1;

  for (int i=2; i<1000000; i++)
    if(prime[i]){
      if(prime[i] / n)
        ans *= prime[i] / n * i;
    }
  
  cout << ans << " ";

  int ret = 0;

  int g = arr[0];
  for (int i=1; i<n; i++){
    g = gcd(arr[i], g);
  }

  if (g == ans) cout << 0;
  else{
    for (int i=0; i<n; i++){
    int gcm = arr[i] / gcd(arr[i], ans) * ans;
    ret += solve(gcm/arr[i]) + solve(gcm/ans);
  }
  cout << ret/2;
  }
  
}


