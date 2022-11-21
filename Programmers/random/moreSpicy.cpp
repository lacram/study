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

int solution(vector<int> scoville, int k) {
  priority_queue<int, vector<int>, greater<>> minheap;

  for (auto s :scoville) {
    minheap.push(s);
  }

  int ans = 0;
  while (minheap.size() != 1 && minheap.top() < k) {
    int a = minheap.top();
    minheap.pop();
    int b = minheap.top();
    minheap.pop();

    minheap.push(a+b*2);
    ans++;
  }
  
  return minheap.top() >= k ? ans : -1;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  //solution();

}