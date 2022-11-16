#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define endl '\n'
#define INF 2000000000

using namespace std;

int solution(vector<int> nums) {
  set<int> s(nums.begin(), nums.end());

  // 최대 종류수와, 가져갈 수 있는 포켓몬 수중 최소
  return min(s.size(), nums.size()/2);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();
  
}