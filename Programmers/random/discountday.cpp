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

map<string, int> wantCnt;

bool check(vector<string> want) {
  for (auto stuff : want) {
    if (wantCnt[stuff] > 0) return false;
  }
  return true;
}

bool checkWant(vector<string> want, string stuff) {
  return find(want.begin(), want.end(), stuff) != want.end();
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
  for (int i=0; i<want.size(); i++) {
    wantCnt[want[i]] = number[i];
  }

  int fr = 0;
  int ans = 0;
  for (int i=0; i<discount.size(); i++) {
    string stuff = discount[i];
    // 필요한 품목이 할인중일 때
    if (checkWant(want, stuff)) {
      wantCnt[stuff]--;
    } 

    // 10일을 채웠을 때 
    if (fr+9 == i) {
      if (check(want)) ans++;
      wantCnt[discount[fr]]++;
      fr++;
    }
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution({"banana", "apple", "rice", "pork", "pot"}  ,    {3, 2, 2, 2, 1}, {"chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana"} );

}