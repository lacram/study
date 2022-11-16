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

// 상위 25이내
int solution(vector<int> levels) {
  if (levels.size() < 4) return -1;

  sort(levels.begin(), levels.end(), greater<>());

  for (int i=0; i<levels.size(); i++) {
    double percent = double(i+1) / levels.size();
    if (percent > 0.25) {
      return levels[i-1];
    }
  }
  return -1;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution({1,2,3});

}