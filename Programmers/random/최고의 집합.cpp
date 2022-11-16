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
typedef long long ll;

using namespace std;


vector<int> solution(int n, int s) {
  int a = s / n; // 몫
  int b = s % n; // 나머지
  if (a == 0) return {-1};
  // 나머지를 나누어줌
  // 총 n번 곱셈
  vector<int> ans;
  for (int i=0; i<n-b; i++) {
    ans.push_back(a);
  }
  for (int i=0; i<b; i++) {
    ans.push_back(a+1);
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