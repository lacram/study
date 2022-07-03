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

map<string, int> mapping;

vector<int> solution(string msg) {
  int idx = 1;
  for (char i = 'A'; i <= 'Z'; i++){
    string str = "";
    str.push_back(i);
    mapping[str] = idx++;
  }

  vector<int> ans;

  for (int i=0; i<msg.size();){
    string str = "";
    int pos = i;
    while (1) {
      str.push_back(msg[pos]);
      if (!mapping[str]){
        // 실패하기 직전 단어 추가
        ans.push_back(mapping[str.substr(0,pos-i)]);
        break;
      }
      pos++;
    }
    mapping[str] = idx++;
    i = pos;
  }

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution("KAKAO");

}