#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int a,int b, int c, int n){
  if (n == 1) {
    cout << a << " " << c << endl;
  }
  else{
    hanoi(a,c,b,n-1);
    cout << a << " " << c << endl;
    hanoi(b,a,c,n-1);
  }
}

int main(){
  int n;
  cin >> n;
  cout << (int)pow(2,n)-1 << endl;
  hanoi(1,2,3,n);
}