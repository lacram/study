#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <set>

using namespace std;

int n,m;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  vector<int> v(n);

  for (int i=0; i<n; i++){
    cin >> v[i];
  }
  sort(v.begin(), v.end());

  cin >> m;

  for (int i=0; i<m; i++){
    int a;
    cin >> a;
    cout << upper_bound(v.begin(), v.end(), a) - lower_bound(v.begin(), v.end(), a) << " ";
  }

}