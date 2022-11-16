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

int solution(int n, int a, int b) {
  int ans = 0;
  while (a != b) {
    if (a % 2 != 0) a++;
    if (b % 2 != 0) b++;
    a /= 2;
    b /= 2;
    ans++;
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