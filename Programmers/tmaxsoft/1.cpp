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

int solution(vector<int> preferences, vector<int> coffees) {
  sort(preferences.begin(), preferences.end());
  sort(coffees.begin(), coffees.end());

  int ans = 0;
  for (int i=0; i<coffees.size(); i++) {
    if (coffees[i] - preferences[i] > 0) {
      ans += coffees[i] - preferences[i];
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

  //solution();

}