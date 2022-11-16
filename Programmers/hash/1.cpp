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

string solution(vector<string> participant, vector<string> completion) {
  map<string,int> num;

  for (auto c : completion) {
    num[c]++;
  }

  for (auto p : participant) {
    num[p]--;
    
    if (num[p] < 0 ) return p;
  }

  return "error";
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}