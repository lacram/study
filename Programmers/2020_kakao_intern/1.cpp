#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int dis(pair<int,int> p1, pair<int,int> p2){
  return abs(p1.first-p2.first) + abs(p1.second-p2.second);
}

string solution(vector<int> numbers, string hand) {
  pair<int,int> p[12] = {
    {3,1},
    {0,0},{0,1},{0,2},
    {1,0},{1,1},{1,2},
    {2,0},{2,1},{2,2},
    {3,0},{3,2}
  };
  int lpos = 10;
  int rpos = 11;
  string answer = "";

  for (auto number: numbers){
     
    if (number == 1 || number == 4 || number == 7){
      answer.append("L");
      lpos = number;
    }
    else if (number == 3 || number == 6 || number == 9){
      answer.append("R");
      rpos = number;
    }
    else {
      if (dis(p[number], p[lpos]) > dis(p[number], p[rpos])){
        answer.append("R");
        rpos = number;
      }
      else if (dis(p[number], p[lpos]) < dis(p[number], p[rpos])){
        answer.append("L");
        lpos = number;
      }
      else {
        if (hand == "right") {
          answer.append("R");
          rpos = number;
        }
        else {
          answer.append("L");
          lpos = number;
        }
      }
    }
  }
  return answer;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution({1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5}	, "right");
}