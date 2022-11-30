#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  int sum = 0;
  int sum2 = 0;

  for (int i=0; i<n; i++){
    int a;
    cin >> a;
    sum += a;
    sum2 += a/2;
  }

  // 총합이 3의 배수여야함
  if (sum % 3 == 0){
    
    // 물은 총합/3일 동안 줌
    // 2의 개수가 물 주는 날보다 커야함
    // 2 = 1+1로 만들 수 있기때문
    if (sum2 >= sum/3)
      cout << "YES";
    else cout << "NO";
  }

  else cout << "NO";
}