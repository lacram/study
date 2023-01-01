#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

int n;
char sign[9];
int arr[10];
int arr2[10];

void swap(int* a, int* b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void compare(int a, int b, int* arr){
  if (sign[a] == '<'){
    if (arr[a]>arr[b]) {
      swap(arr[a], arr[b]);
      compare(a-1, a, arr);
    }
  }
  if (sign[a] == '>'){
    if (arr[a]<arr[b]) {
      swap(arr[a], arr[b]);
      compare(a-1, a, arr);
    }
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    cin >> sign[i];
  }

  for (int i=0; i<=n; i++){
    arr[i] = 9-i;
    arr2[i] = i;
  }
  
  for (int i=0; i<n; i++){
    compare(i,i+1,arr);
    compare(i,i+1,arr2);
  }
  
  for (int i=0; i<=n; i++)
    cout << arr[i];
  cout << endl;  
  for (int i=0; i<=n; i++)
    cout << arr2[i];
}