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

int cnt[101];

void getFactor(int num) {
  int arr[101] = {};
  int k = 2;
  while (num > 1) {
    while (num % k == 0) {
      arr[k]++;
      num /= k;
    }
    k++;
  }
  for (int i=2; i<101; i++) {
    cnt[i] = max(cnt[i], arr[i]);
  }
}

int solution(vector<int> arr) {
  for (auto a : arr) {
    getFactor(a);
  }
  int ans = 1;
  for (int i=2; i<101; i++) {
    ans *= pow(i,cnt[i]);
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