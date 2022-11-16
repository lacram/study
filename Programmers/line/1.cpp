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

vector<pair<int,int>> arr(1001);

int solution(vector<vector<int>> queries) {
  int ans = 0;
  for (auto query: queries) {
    int num = query[0];
    int cnt = query[1];

    // 첫 추가는 계산 x
    if (arr[num].first == 0) {
      int i = 0;
      while(pow(2,i) < cnt) {
        i++;
      }
      arr[num] = {cnt,pow(2,i)};
    } else{
      int total = arr[num].first;
      int maxCnt = arr[num].second;

      if (total + cnt > maxCnt) {
        ans += total;
        arr[num] = {total+cnt,maxCnt*2};
      } else {
        arr[num] = {total+cnt,maxCnt};
      }
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

  vector<vector<int>> v(100000);
  for (int i=0; i<100000; i++) {
    v[i] = {1000,10000};
  }

  cout << solution({{1,1}});

}