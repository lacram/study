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

/* 
완탐
. 만날시 pos+1~pos+k에 다음 알파벳이 등장하면 매칭 가능
 */

string solution(int k, vector<string> dic, string chat) {

  vector<string> words;
  int pos = 0;
  while ((pos = chat.find(" ")) != string::npos) {
    words.push_back(chat.substr(0,pos));
    chat = chat.substr(pos+1);
  }
  words.push_back(chat);

  string ans = "";
  for (auto word : words) {
    for (auto str : dic) {
      int idx = 0;
      for (int i=0; i<word.size(); i++) {
        // .일경우
        if (word[i] == '.') {
          // . 만날시 pos+1~pos+k에 다음 알파벳이 등장하면 매칭 가능
          for (int j=idx+1; j<=idx+k; j++) { 
            if (str[j] == word[i+1] || word[i+1] == '.') {
              idx = j;
              break;
            }
          }
        }
        // 알파벳일 경우
        else {
          if (word[i] == str[idx]) {
            idx++;
          }
        }

      }
    }
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