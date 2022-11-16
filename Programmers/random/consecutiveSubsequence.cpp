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

int solution(vector<int> elements) {
  int n = elements.size();
  for (int i=0; i<n; i++) {
    elements.push_back(elements[i]);
  }

  set<int> s;
  // 사이즈
  for (int i=0; i<n; i++) {
    int ans = 0;
    for (int j=i; j<i+n; j++) {
      ans += elements[j];
      s.insert(ans);
    }
  }
  
  return s.size();
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution({7,9,1,1,4});

}