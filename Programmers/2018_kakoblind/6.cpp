#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#define endl '\n'
#define INF 2000000000

using namespace std;

int w;

vector<int> getLine(int n){
  vector<int> v;
  while (n) {
    v.push_back(n%2);
    n /= 2;
  }
  return v;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
  vector<string> ans(n);
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      ans[i].push_back(' ');

  int w = n;

  for (int i=0; i<n; i++){
    vector<int> line = getLine(arr1[i]);
    vector<int> line2 = getLine(arr2[i]);
    for (int j=0; j<line.size(); j++){
      if (line[j]) ans[i][n-1-j] = '#';
    }
    for (int j=0; j<line2.size(); j++){
      if (line2[j]) ans[i][n-1-j] = '#';
    }
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  vector<string> ans = solution(6, {46, 33, 33 ,22, 31, 50} , {27 ,56, 19, 14, 14, 10});

}