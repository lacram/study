#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <string>
#define endl '\n'

using namespace std;

int n;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  ifstream cin;
  cin.open("input.txt");

  string str;
  getline(cin, str);
  
  for (int i=0; i<str.length(); i++){
    if (str[i] == '[')
      str[i] = '{';
    if (str[i] == ']')
      str[i] = '}';
  }
  cout << str;

}