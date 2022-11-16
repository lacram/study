#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <sstream>
#define endl '\n'
#define INF 2000000000

using namespace std;

/* 
공백 단위로 구분
정수 치환 
정렬
 */
string solution(string s) {
  stringstream ss(s);
  string num = "";
  vector<int> v;
  while (ss >> num) {
    v.push_back(stoi(num));
  }
  sort(v.begin(), v.end());

  return to_string(v.front()) + " " + to_string(v.back());
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution("-1 -2 -3 -4");

}