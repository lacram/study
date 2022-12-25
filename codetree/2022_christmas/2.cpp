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
간격 map에 저장
 */
int n;
int arr[1000];  

int solution() {
  map<int,int> m;
  for (int i=0; i<n-1; i++) {
    int diff = arr[i+1]-arr[i];
    m[diff]++;
  }
  
  vector<pair<int,int>> v(m.begin(), m.end());
  sort(v.begin(), v.end());

  return v.front().second;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;
  for (int i=0; i<n; i++)
    cin >> arr[i];

  cout << solution();

}