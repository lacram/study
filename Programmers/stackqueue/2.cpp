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

bool solution(string str) {

  int cnt = 0;
  for (auto c : str) {
    if (c == '(') cnt++;
    else cnt--;
    if (cnt < 0) return false;
  }

  return !cnt;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}