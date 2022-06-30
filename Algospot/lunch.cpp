#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
using namespace std;


int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  // ifstream cin;
  // cin.open("input.txt");

  int test, n;
  cin >> test;

  while (test--){
    cin >> n;

    vector<int> mvtime(n);
    for (int i=0; i<n; i++){
      cin >> mvtime[i];
    }
    vector<pair<int,int>> order;
    vector<int> eattime(n); 
    for (int i=0; i<n; i++){
      cin >> eattime[i];
      order.push_back(make_pair(-eattime[i], i));
    }

    sort(order.begin(), order.end());

    int ret = 0;
    int time=0;
    for(int i=0; i<n; i++){
      int box = order[i].second;
      time += mvtime[box];
      ret = max(ret, time + eattime[box]);
    }
    cout << ret << endl;
  }
  
}