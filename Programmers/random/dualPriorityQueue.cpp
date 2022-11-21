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
#include <sstream>
#define endl '\n'
#define INF 2000000000

using namespace std;

vector<int> solution(vector<string> operations) {
  priority_queue<int> maxheap;
  priority_queue<int, vector<int>, greater<int>> minheap;
  int cnt = 0;
  for (auto operation : operations) {
    stringstream ss(operation);
    char op;
    int num;
    ss >> op >> num;

    if (op == 'I') {
      maxheap.push(num);
      minheap.push(num);
      cnt++;
    } else if (op == 'D' && cnt){
      if (num == 1) {
        maxheap.pop();
      } else {
        minheap.pop();
      }
      cnt--;
    }
    if (cnt == 0) {
      while (!maxheap.empty()) maxheap.pop();
      while (!minheap.empty()) minheap.pop();
    }
  }
  vector<int> ans;
  if (maxheap.empty()) ans.push_back(0);
  else ans.push_back(maxheap.top());
  if (minheap.empty()) ans.push_back(0);
  else ans.push_back(minheap.top());

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