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
가장 무거운사람부터 가장 가벼운 사람 가능할시 추가
 */
int solution(vector<int> people, int limit) {
  
  sort(people.begin(), people.end());

  int ans = 0;
  int lo = 0;
  int hi = people.size()-1;

  while (lo <= hi) {
    if (people[hi] + people[lo] <= limit) {
      lo++; 
    } 
    ans++;
    hi--;
    
    if (lo == hi) {
      return ans+1;
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