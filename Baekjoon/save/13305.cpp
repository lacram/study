#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

int n;
int costs[100000];
int dist[100000];

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n-1; i++){
    cin >> dist[i];
  }
  for (int i=0; i<n; i++){
    cin >> costs[i];
  }

  long long ans = 0;
  
  int cost = costs[0];

  for (int i=1; i<n; i++){
    ans += cost*dist[i-1];
    if (cost > costs[i])
      cost = costs[i];
  }

  cout << ans;
}