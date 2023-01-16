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

int n;
int dpA[46];
int dpB[46];

int fibonacciA(int n) {
  if (n == 1) return 0;
  if (n == 2) return 1;

  int& ret = dpA[n];
  if (ret != -1) return ret;
  return ret = fibonacciA(n-2) + fibonacciA(n-1);
}

int fibonacciB(int n) {
  if (n == 1) return 1;
  if (n == 2) return 1;

  int& ret = dpB[n];
  if (ret != -1) return ret;
  return ret = fibonacciB(n-2) + fibonacciB(n-1);
}

/* 
A로 시작
B -> BA
A -> B

A - 0 1 1 2 3
B - 1 1 2 3 5

BABBA -> BABBABAB
 */

void solution() {
  memset(dpA, -1 ,sizeof(dpA));
  memset(dpB, -1 ,sizeof(dpB));

  cout << fibonacciA(n) << " " << fibonacciB(n);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  solution();
}