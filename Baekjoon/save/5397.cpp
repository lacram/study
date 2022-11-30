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
string s;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    cin >> s;
    list<char> str;
    list<char>::iterator it = str.begin();

    for (int j=0; j<s.length(); j++){
      if (s[j] == '<') {
        if(it != str.begin()) 
          it--;
      }
      else if (s[j] == '>') {
        if(it != str.end())
          it++;
      }
      else if (s[j] == '-') {
        if (str.size() == 0) continue;
        if (it == str.begin()) continue;
        it--;
        it = str.erase(it);
      }
      else str.insert(it, s[j]);
    }

    for (auto a : str)
      cout << a;
    cout << endl;
  }

}