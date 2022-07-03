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

// 원으로 생각
int solution(vector<int> queue1, vector<int> queue2) {
  vector<int> circle;
  long long cnt1 = 0;
  long long cnt2 = 0;
  
  for (auto q : queue1) {
    circle.push_back(q);
    cnt1 += q;
  }

  for (auto q : queue2) {
    circle.push_back(q);
    cnt2 += q;
  }
  
  int n = circle.size();
  for (int i=0; i<n; i++)
    circle.push_back(circle[i]);
  
  int lo1 = 0;
  int hi1 = queue1.size()-1;
  int lo2 = queue1.size();
  int hi2 = queue1.size()+queue2.size()-1;

  int ans = 0;
  while (hi2 < (queue1.size()+queue2.size())*2) {
    if (cnt1 == cnt2) return ans;

    if (cnt1 < cnt2) {
      hi1++;
      lo2++;
      cnt1 += circle[hi1];
      cnt2 -= circle[hi1];
    }
    else {
      lo1++;
      hi2++;
      cnt1 -= circle[hi2];
      cnt2 += circle[hi2];
    }

    ans++;
  }

  return -1;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution({1, 2, 1, 2},    {1, 10, 1, 2} );

}