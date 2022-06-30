#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

string str;

bool solve(){
  int cntP = 0;

  for (int i=0; i<str.length(); i++){
    if (str[i] == 'P')
      cntP++;

    if (str[i] == 'A'){
      if (str[i+1] == 'A' || i == str.length()-1) {
        return false;
      }
      if (str[i+1] == 'P') {
        if (cntP < 2) {
          return false;
        }
        cntP -= 2;
      }
    }
  }
  return cntP == 1;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> str;

  if (solve()) cout << "PPAP";
  else cout << "NP";
}