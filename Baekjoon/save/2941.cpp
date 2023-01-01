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
#include <set>
#define endl '\n'
#define INF 2000000000

using namespace std;

int n;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  string str = "12345";

  cin >> str;

  vector<string> arr = {"c=","c-","dz=","d-","lj","nj","s=","z="};

  for (auto word : arr) {
    int pos = -1;
    while ((pos = str.find(word)) != string::npos) {
      str.replace(pos,word.size(),"1");
    }
  }

  cout << str.size();
}