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

int arr[10];

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");
  
  vector<int> v1 = {1,6};
  vector<int> v2 = {1,6};
  string a(v1.begin(), v1.end());
  string b(v2.begin(), v2.end());
  cout << a << endl << b;
}