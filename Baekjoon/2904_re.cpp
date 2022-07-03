#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

#define MAX 1000000

using namespace std;

int n;
int arr[100];

int minFactor[MAX+1];
int factor[MAX+1];
int gcdFactor[1000] = {0};
int cmpFactor[1000];

void updateFactor(){
  for (int i=2; i<=MAX; i++)
    minFactor[i] = i;
  
  for (int i=2; i<=sqrt(MAX); i++)
    if (minFactor[i] == i)
      for (int j=i*i; j<=MAX; j+=i)
        if (minFactor[j] == j)
          minFactor[j] = i;
}

void getFactorCnt(int num, int* arr){
  while (num > 1){
    arr[minFactor[num]]++;
    num /= minFactor[num];
  }
}

void getFactorCnt1000(int num, int* arr){
  while (num > 1){
    if (minFactor[num] > 1000) return;
    arr[minFactor[num]]++;
    num /= minFactor[num];
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  updateFactor();

  for (int i=0; i<n; i++){
    cin >> arr[i];
    getFactorCnt(arr[i], factor);
  }

  int ans = 1;

  for (int i=0; i<=MAX; i++){
    if (factor[i] >= n){
      ans *= pow(i, factor[i] / n);  
    }
  }

  cout << ans << " ";

  getFactorCnt1000(ans, gcdFactor);
  int cnt = 0;

  for (int i=0; i<n; i++){
    memset(cmpFactor, 0 , sizeof(cmpFactor));

    getFactorCnt1000(arr[i], cmpFactor);

    for (int j=0; j<1000; j++){
      if (gcdFactor[j] > cmpFactor[j])
        cnt += gcdFactor[j] - cmpFactor[j];
    }
  }

  cout << cnt;
}