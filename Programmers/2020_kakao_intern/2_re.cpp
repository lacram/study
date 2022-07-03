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

/* 
1. 숫자, 수식 단위로 토큰화
2. ex1 계산결과를 ex2에 저장 ex1 = ex2
3. 가장 큰 값 계산
*/

vector<string> calc(vector<string> ex, char op) {
  
  for (auto it=ex.begin(); it != ex.end(); it++) {
    if (*it == string(1, op)) {
      long long a = stoll(*(it-1));
      long long b = stoll(*(it+1));
      long long ans;

      if (op == '+') ans = a+b;
      if (op == '-') ans = a-b;
      if (op == '*') ans = a*b;

      it = ex.erase(it-1, it+2);
      ex.insert(it,to_string(ans));
    }
  }

  return ex;
}

long long solution(string expression) {
  vector<string> ex;
  int pos = 0;

  for (int i=0; i<expression.size(); i++) {
    if (!isdigit(expression[i])) {
      ex.push_back(expression.substr(pos,i-pos));
      ex.push_back(string(1, expression[i]));
      pos = i+1;
    }
  }
  ex.push_back(expression.substr(pos,expression.size()-pos));


  vector<string> per = {"+-*","-+*","+*-","-*+","*+-","*-+"};

  long long ans = 0;

  for (auto ops : per) {
   vector<string> tmp = ex;

    for (auto op : ops) {
      tmp = calc(tmp,op);
    }

    ans = max(ans, abs(stoll(tmp[0])));
  }

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution("100-200*300-500+20");

}