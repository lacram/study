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

int day[366];

int solution(vector<vector<int>> flowers) {
  for (auto flower : flowers) {
    int fr = flower[0];
    int to = flower[1];

    for (int i=fr; i<to; i++) {
      day[i] = 1;
    }
  }

  int ans = 0;
  for (int i=1; i<=365; i++) {
    if (day[i]) ans++;
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