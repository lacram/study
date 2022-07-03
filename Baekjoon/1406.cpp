#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <list>
#define endl '\n'

using namespace std;

int n;
list<char> str;
list<char>::iterator cursor;
char word;

void solve(char s){
  if (s == 'L'){
    if (cursor != str.begin()) cursor--;
  }
  if (s == 'D'){
    if (cursor != str.end()) cursor++; 
  }
  if (s == 'B'){
    if (cursor != str.begin()) {
      cursor--;
      cursor = str.erase(cursor); 
    }
  }
  if (s == 'P'){
    str.insert(cursor,word);
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");
  string a;

  cin >> a;
  for (int i=0; i<a.size(); i++)
    str.push_back(a[i]);

  cin >> n;
  cursor = str.end();

  for (int i=0; i<n; i++){
    char s;
    cin >> s;
    if (s == 'P') 
      cin >> word;
    solve(s);
  }
  
  for (auto a : str)
    cout << a;
}