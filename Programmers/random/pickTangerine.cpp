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

map<int,int> countTangerine;

void mapping(vector<int> tangerine) {
  for (auto t : tangerine) {
    countTangerine[t]++;
  }
}

bool compare(pair<int,int> p1, pair<int,int> p2) {
  return p1.second > p2.second;
}

vector<pair<int,int>> sortByValue() {
  vector<pair<int,int>> tmp(countTangerine.begin(), countTangerine.end());
  sort(tmp.begin(), tmp.end(), compare);
  return tmp;
}

int getAns(vector<pair<int,int>> v, int k) {
  int cnt = 0;
  for (auto a : v) {
    k -= a.second;
    cnt++;
    if (k <= 0) {
      return cnt;
    }
  }
}

int solution(int k, vector<int> tangerine) {
  mapping(tangerine);
  return getAns(sortByValue(), k);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}