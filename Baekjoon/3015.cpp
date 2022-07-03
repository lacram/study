#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <stack>
#define endl '\n'

using namespace std;

int n,height;
long long ans;
stack<pair<int,int>> s;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    cin >> height;

      // 큰 키 
    while (!s.empty() && height > s.top().first){
      ans += s.top().second;
      s.pop();
    } 
    // 비어있음
    if (s.empty()) 
      s.push(make_pair(height,1));

    else{    
      // 같은 키
      if (s.top().first == height){
        int cur = s.top().second;
        s.pop();
        if (!s.empty()) ans++;
        
        ans += cur;
        s.push(make_pair(height,cur+1));
      }
      // 작은 키
      else{
        ans += 1;
        s.push(make_pair(height,1));
      }
    }
  }
  
  cout << ans;
}