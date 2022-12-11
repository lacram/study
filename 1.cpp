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
  
  // map<int,int> m = {{1,2},{2,3}};
  vector<pair<int,int>> m = {{1,2},{2,3}};

  for (auto [key,value] : m) {
    cout << key << " " << value << endl;
  }
}