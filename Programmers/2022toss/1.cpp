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

bool isSame(string num) {
  if ((num[0] == num[1]) && (num[1] == num[2])) return true;
  return false;
} 

int solution(string s) {
  int maxNum = -1;
  if (s.size() < 3) return maxNum;

  for (int i=0; i<s.size()-2; i++) {
    string num = "";

    for (int j=i; j<i+3; j++) {
      num.push_back(s[j]);
    }
    
    if (isSame(num)) {
      maxNum = max(maxNum, stoi(num));
    }
  }

  return maxNum;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution("999");

}