#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,m;
vector<pair<int,int>> order;
vector<pair<int,int>> bus;

bool compare(pair<int,int> p1, pair<int,int> p2){
  if (p1.first == p2.first) return p1.second >= p2.second;
  return p1.first <= p2.first;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  order.resize(n);
  bus.resize(m);

  for (int i=0; i<n; i++){
    int a,b;
    cin >> a >> b;
    order[i] = {a,b};
  }
  for (int i=0; i<m; i++){
    int a,b;
    cin >> a >> b;
    bus[i] = {a,b};
  }

  sort(order.begin(), order.end(), compare);
  sort(bus.begin(), bus.end(), compare);

  int ans = 0;
  int t = 0;

  for (int i=0; i<order.size(); i++)
    for (int j=t; j<bus.size(); j++){
      if (order[i].first > bus[j].first || order[i].second < bus[j].second) continue;

      t = j+1;
      ans++;
      break;
    }
  cout << ans;
}