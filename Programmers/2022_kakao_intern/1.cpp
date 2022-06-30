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
R T
C F
J M
A N
 */
string solution(vector<string> survey, vector<int> choices) {
  map<char,int> score;

  for (int i=0; i<survey.size(); i++) {
    string str = survey[i];
    char fir = str[0];
    char sec = str[1]; 

    int c = choices[i];
    // 앞글자에 동의
    if (1 <= c && c <= 3) {
      score[fir] += 4-c;
    }
    // 뒷글자에 동의
    if (5 <= c && c <= 7) {
      score[sec] += c-4;
    }
  }

  string ans = "";

  score['R'] >= score['T'] ? ans.push_back('R') : ans.push_back('T');
  score['C'] >= score['F'] ? ans.push_back('C') : ans.push_back('F');
  score['J'] >= score['M'] ? ans.push_back('J') : ans.push_back('M');
  score['A'] >= score['N'] ? ans.push_back('A') : ans.push_back('N');

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}