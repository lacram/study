#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  int i = 665, cnt=0;
  while(cnt != n){
    i++;
    if (to_string(i).find("666") != string::npos)
      cnt++;
  }
  cout << i;
  
}