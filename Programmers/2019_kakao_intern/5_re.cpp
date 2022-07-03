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

/* 
1. 이분탐색
2. 돌에 적힌 숫자 s이 pnum보다 작을 경우 cnt++, 클 경우 cnt = 1
3. cnt > k 일시 실패
 */

vector<int> stones;
int k;

bool decision(int pnum) {
  int cnt = 1;
  for (auto stone : stones) {
    if (stone < pnum) cnt++;
    else cnt = 1;

    if (cnt > k) return false;
  }
  return true;
}

int solution(vector<int> s, int K) {
  stones = s;
  k = K;

  int lo = 1;
  int hi = 200000000;

  while (lo <= hi) {
    int mid = (lo+hi)/2;
    if (decision(mid)) lo = mid+1;
    else hi = mid-1;
  }

  return hi;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}