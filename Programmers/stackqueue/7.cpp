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

vector<string> words;
string s = "AEIOU";

void makeWord(int depth, string str) {
  if (depth == 5) return;

  for (int i=0; i<5; i++) {
    words.push_back(str+s[i]);
    makeWord(depth+1, str+s[i]);
  }
}

int solution(string word) {
  makeWord(0,"");

  return find(words.begin(), words.end(), word) - words.begin() + 1;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}