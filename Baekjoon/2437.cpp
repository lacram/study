#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <set>
#define endl '\n'

using namespace std;

int n;
int chu[1000];

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    cin >> chu[i];
  }

  sort(chu, chu+n);

  int total = 1;
  for (int i=0; i<n; i++){
    if (total < chu[i]){
      break;
    }
    else{
      total += chu[i];
    }
  }

  cout << total;
}