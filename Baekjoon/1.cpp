#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define endl '\n'
#define INF 2000000000

using namespace std;

int n;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cin >> n;

  set<int> s = {1,2,3,4,5,6};

  for (auto it = s.begin(); it != s.end(); it++) {
    if (*it == 3) {
      cout << *it << "del" << endl;
      it = s.erase(it);
      continue;
    }
    cout << *it;
  }
  
}