#include <bits/stdc++.h>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

int MAX = 5000000;
int n;
int minFactor[5000001];

void eratos(){
  for (int i=2; i<=MAX; i++)
    minFactor[i] = i;

  int sqrtn = sqrt(MAX);
  for (int i=2; i<=sqrtn; i++)
    if(minFactor[i]==i)
      for (int j=i*i; j<=MAX; j+=i)
        if(minFactor[j]==j)
          minFactor[j]=i;
}

void solve(int x){
  while (x != 1){
    cout << minFactor[x] << " ";
    x /= minFactor[x];
  }
  cout << '\n';
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  eratos();

  for (int i=0; i<n; i++){
    int x;
    cin >> x;

    solve(x);
  }

}