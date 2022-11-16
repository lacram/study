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

int n;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cin >> n;

  vector<vector<int>> v = {{5,8,1}, {5,7,3}, {5,8,4}, {5,7,2}};

  sort(v.begin(), v.end(), greater<>());

  cout << 1;
}