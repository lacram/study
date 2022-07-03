#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;

int prime[10000];

void eratos(){
  for (int i=2; i<10000; i++)
    prime[i] = 1;

  for (int i=2; i<=100; i++)
    if (prime[i])
      for (int j=i*i; j<10000; j+=i)
        prime[j] = 0;
}

int solve(int num){
  for (int x = num/2; x>0; x--)
    if (prime[x] && prime[num-x])
      return x;
  return -1;
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
    int num;
    cin >> num;
    int x = solve(num);
    int y = num - x;
    cout << x << " " << y << endl;
  }

}