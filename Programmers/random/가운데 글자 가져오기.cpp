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

string solution(string s) {
  // 짝수
  if (s.size() % 2 == 0) {
    return s.substr(s.size()/2-1, 2);
  } else {
    string ans = "";
    return ans + s[s.size()/2];
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}