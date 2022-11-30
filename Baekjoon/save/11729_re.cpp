#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;

void hanoi(int fr, int mid, int to, int n){
  if (n==1) 
    cout << fr << " " << to << endl;
  else{
    hanoi(fr, to, mid, n-1);
    cout << fr << " " << to << endl;
    hanoi(mid, fr, to, n-1);
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  cout << (int)pow(2,n)-1 << endl;
  hanoi(1,2,3,n);

}