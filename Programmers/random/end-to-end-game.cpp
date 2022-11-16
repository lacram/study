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
뒷단어를 잇는지 검사
중복인지 검사
탈락자라면 idx % n +1 번호, (idx / size) + 1 차례
 */

map<string,int> record;

bool isRightWord(string before, string after) {
  return before.back() == after.front();
}

bool isDuplicated(string word) {
  return record[word] != 0;
}

vector<int> solution(int n, vector<string> words) {
  
  for (int i=0; i<words.size(); i++) {
    if ((i > 0 && !isRightWord(words[i-1], words[i])) || isDuplicated(words[i])) {
      int num = (i % n) + 1;
      int order = (i / n) + 1;
      return {num, order};
    }

    record[words[i]] = 1;
  }
  return {0,0};
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution(3    ,   {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"});

}