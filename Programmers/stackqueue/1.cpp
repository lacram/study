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

vector<int> solution(vector<int> arr) {
  vector<int> ans;

  int last = -1;
  for (auto a : arr) {
    if (a != last) {
      ans.push_back(a);
      last = a;
    }
  } 
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