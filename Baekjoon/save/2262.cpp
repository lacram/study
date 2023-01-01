#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,num = 0;
vector<int> arr;

int solve(){
  int ans = 0;

  // n-1번 경기해야 1등 나옴
  for (int i=n; i>=2; i--){
    vector<int>::iterator it = arr.begin();

    while (*it != i){
      it++;
    }

    // i등이 맨 처음에 위치
    if (it == arr.begin()){
      it = arr.erase(it);
    }
    // i등이 맨 끝에 위치
    else if (it == arr.end()-1){
      arr.erase(it);
      it = arr.end()-1;
    }
    else {
      // 왼쪽이랑 붙을경우
      if (*(it-1) > *(it+1)){
        it = arr.erase(it);
        it--; 
      }
      // 오른쪽이랑 붙을경우
      else{
        it = arr.erase(it);
      }
    }
    ans += i-*it;
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    int a;
    cin >> a;
    arr.push_back(a);
  }
  
  cout << solve();
}