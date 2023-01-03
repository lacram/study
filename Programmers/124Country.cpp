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

/*
3진법
0 1 2
1 2 4
 */

string getAns(int n) {
  string str = "";
  while (n) {
    if (n%3 == 0) {
      str.push_back('4');
      n--;
    }
    else str.push_back(n%3+'0');
    n /= 3;
  }
  reverse(str.begin(), str.end());
  return str;
}

string solution(int n) {
  return getAns(n);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}