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

int solution(vector<int> food_times, long long k) {
  int n = food_times.size();
  k++;
  vector<int> sorted(n);
  copy(food_times.begin(), food_times.end(), sorted.begin());

  sort(sorted.begin(), sorted.end());

  long long cycle = 0;

  for (int i=0; i<n; i++){
    long long rPeople = n-i;
    int toCycle = sorted[i]-cycle;

    if (k > toCycle*rPeople) {
      k -= toCycle*rPeople;
      int t = i;
      while (t != n-1 && sorted[t] == sorted[t+1]) {
        t++;
      }
      i = t;
      cycle += toCycle;
    }
    else {
      while (k > rPeople){
        k -= rPeople;
      }
      for (int i=0; i<n; i++) {
        if (food_times[i] > cycle) k--;
        
        if (k == 0) return i+1;
      }
      return -1;
    }
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution({3,1,1,1,2,4,3},12);

}