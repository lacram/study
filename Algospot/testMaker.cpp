#include<iostream>
#include<vector>
#include<random>
using namespace std;
int main(){
  
  random_device rd;
  // 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
  uniform_int_distribution<int> dis(0, 99);
  int n = 10;
  vector<int> input(n); //vector input 크기를 n으로 설정
  for(int i=0; i<n; i++){
    input[i] = dis(rd);
  }
  for (int i=0; i<input.size(); i++){
    cout << input[i] << endl;
  }
}