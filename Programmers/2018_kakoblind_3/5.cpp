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

string getNumbers(int num, int n){
  if (num == 0) return "0";
  
  string numbers = "";
  while(num){
    int remainder = num % n;
    if (remainder >= 10){
      numbers.push_back(remainder-10 + 'A');
    }
    else numbers.push_back(remainder + '0');

    num /= n;
  }
  
  reverse(numbers.begin(), numbers.end());
  return numbers;
}

// 진법 n, 미리 구할 숫자의 갯수 t, 게임에 참가하는 인원 m, 튜브의 순서 p 가 주어진다.
string solution(int n, int t, int m, int p) {
  string numbers = "";
  
  for (int i=0; i<= t*(m+1); i++){
    numbers += getNumbers(i,n);
  }
  
  string ans = "";
  for (int i=0; i<t; i++){
    ans.push_back(numbers[p-1 + m*i]);
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution(2,4,2,1);

}