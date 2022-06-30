#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,k;
int arr[40];
long long used=0;
bool fin = false;
int binary[40];
int pos[40];

void solve(int sum){
  if (fin) return;
  if (sum == k){
    fin = true;
    int t = 0;

    while(used){
      int bi = used % 2;
      used /= 2;
      binary[t] = bi;
      t++;
    }
    for (int i=0; i<n; i++)
      cout << binary[i];
    return;
  }

  for (int i=0; i<n; i++){
    if (arr[i] + sum > k || (used & (1<<i))) continue;
    used |= (long long) 1<<i;
    solve(sum+arr[i]);
    used &= ~((long long) 1<<i);
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

  cin >> k;

  solve(0);
}