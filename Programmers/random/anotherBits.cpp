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
제일 작은 0을 1로, 이후로 큰 1을 0으로
 */

long long getAns(long long number) {

  long long n = 1;

  while ((number | n) == number) n <<= 1;

  return number + n - n/2;
}

vector<long long> solution(vector<long long> numbers) {
  vector<long long> ans;
  for (auto number : numbers) {
    ans.push_back(getAns(number));
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution({7});

}