#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#define endl '\n'
#define INF 2000000000

using namespace std;

set<int> s;
int n;
int visited[7];

void makeNumber(string myNum, string numbers) {
  if (myNum != "") s.insert(stoi(myNum));

  for (int i=0; i<n; i++) {
    if (visited[i]) continue;
    visited[i] = 1;
    makeNumber(myNum + numbers[i], numbers);
    visited[i] = 0;
  }
}

bool isPrime(int num) {
  if (num <= 1) return false;
  for (int i=2; i<=sqrt(num); i++) {
    if (num % i == 0) return false;
  }
  return true;
}

int getAns() {
  int ans = 0;
  for (auto a : s) {
    if (isPrime(a)) ans++;
  }
  return ans;
}

int solution(string numbers) {
  n = numbers.size();

  makeNumber("",numbers);

  return getAns();
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution("1234");

}