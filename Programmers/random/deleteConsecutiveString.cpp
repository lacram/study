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
스택에 전부 담기
같으면 담지 않기
스택사이즈가 0이면 성공
 */


int solution(string s){
  stack<char> st;
  for (auto w : s) {
    if (!st.empty() && st.top() == w) {
      st.pop();
    } else {
      st.push(w);
    }
  }
  return st.size() == 0;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution("baabaa");
}