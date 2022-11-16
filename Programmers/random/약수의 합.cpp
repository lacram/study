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

int solution(int n) {
  int ans = 0;
  for (int i=1; i<sqrt(n); i++) {
    if (n % i == 0) {
      ans += i + n/i;
    }
  }
  if ((int)sqrt(n)*sqrt(n) == n) ans += sqrt(n);

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