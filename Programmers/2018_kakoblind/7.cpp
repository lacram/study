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
#define endl '\n'
#define INF 2000000000

using namespace std;

int solution(string dartResult) {
  int cur = 0;
  int prev = 0;
  int tmp;
  int ans = 0;
  string dr = dartResult;

  for (int i=0; i<dr.size(); i++){
    if ('0' <= dr[i] && dr[i] <= '9'){
      if (prev) ans += prev;
      prev = cur;

      // 10
      if (dr[i+1] == '0') {
        tmp = stoi(dr.substr(i,2));
        i++;
      }
      else tmp = dr[i]-'0';
    }
    else if (dr[i] == 'S') {
      cur = pow(tmp,1);
    }
    else if (dr[i] == 'D') {
      cur = pow(tmp,2);
    }
    else if (dr[i] == 'T') {
      cur = pow(tmp,3);
    }
    else if (dr[i] == '*') {
      prev *= 2;
      cur *= 2;
    }
    else if (dr[i] == '#') {
      cur *= -1;
    }
  }
  return ans+prev+cur;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution("10D4S10D");

}