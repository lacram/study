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

int dp[100001];

int fibonacci(int n) {
  if (n == 1) return 1;
  if (n == 2) return 1;
  return (fibonacci(n-2) + fibonacci(n-1)) % 1234567;
}

int solution(int n) {
  return fibonacci(n);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}