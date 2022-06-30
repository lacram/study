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
#define ll long long

using namespace std;

vector<long long> num;
vector<int> v;
map<char, int> m = {
  {'+',-1},
  {'-',-2},
  {'*',-3}
};

long long answer = 0;
bool used[3];

ll calc(ll a, ll b, int n){
  if (n == -1) return a + b;
  if (n == -2) return a - b;
  if (n == -3) return a * b;
}

ll getAns(){
  vector<ll> num2(num.size());
  copy(num.begin(), num.end(), num2.begin());
  ll tmp = 0;

  for (int i=0; i<3; i++){
    for (vector<ll>::iterator it=num2.begin(); it!=num2.end(); it++){
      if (*it == v[i]){
        tmp = calc(*(it-1),*(it+1), *it);
        it = num2.erase(it-1,it+2);
        num2.insert(it, tmp);
      }
    }
  }

  return abs(tmp);
}

void dfs(int n){
  if (n == 3){
    answer = max(answer, getAns());
  }

  for (int i=0; i<3; i++){
    if (used[i]) continue;
    used[i] = 1;
    v.push_back(i-3);
    dfs(n+1);
    v.pop_back();
    used[i] = 0;
  }
}

long long solution(string expression) {
  string tmp="";
  answer = 0;
  
  for (int i=0; i<expression.length(); i++){
    if (expression[i] - '0' >= 0 && expression[i] - '0' <= 9){
      tmp.push_back(expression[i]);
    }
    else {
      num.push_back(stoul(tmp));
      tmp = "";
      num.push_back(m[expression[i]]);
    }
  }
  num.push_back(stol(tmp));

  dfs(0);
  
  return answer;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution("100-200*300-500+20");

}