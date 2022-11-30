#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#define endl '\n'

using namespace std;

int n,k;
int ranking[300000];
deque<int> student[21];

long long solve(){
  long long ans = 0;

  for (int i=0; i<n; i++){
    deque<int> &deq = student[ranking[i]];
    deq.push_back(i);
    if (deq.size() == 1) continue;
    
    while (i - deq.front() > k){
      deq.pop_front();
    }
    ans += deq.size()-1;
  }

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> k;

  for (int i=0; i<n; i++){
    string a;
    cin >> a;
    ranking[i] = a.size();
  }

  cout << solve();
}