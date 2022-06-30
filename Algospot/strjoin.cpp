#include <queue>
#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  // ifstream cin;
  // cin.open("input.txt");

  int test, n;
  cin >> test;

  while (test--){
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> q;
    for (int i=0; i<n; i++){
      int a;
      cin >> a;
      q.push(a);
    }

    int ans=0;
    while (q.size() != 1){
      int x = 0;
      for(int i=0; i<2; i++){
        x += q.top();
        q.pop();
      }
      ans += x;
      q.push(x);
    }

    cout << ans << endl;
  }
  
}