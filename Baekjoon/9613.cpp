#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#define endl '\n'

using namespace std;

int test, n;

int gcd(int x, int y){
  if (y == 0 ) return x;
  return gcd(y, x%y);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cin >> test;
  while(test--){
    cin >> n;

    int arr[n];

    for (int i=0; i<n; i++){
      cin >> arr[i];
    }

    long long ans = 0;

    for (int i=0; i<n; i++)
      for (int j=i+1; j<n; j++)
        ans += gcd(arr[i], arr[j]);
    
    cout << ans << endl;
  }
}