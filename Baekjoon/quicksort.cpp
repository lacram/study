#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int* arr;

void swap(int *a, int* b){
  int tmp = *a;
  *a = *b;
  *b = *a;
}

void print(int p,int r,int end){
  cout << "divide = ";
  cout << arr[p] << "|";
  for (int i=p+1; i<r; i++)
    cout << arr[i] << " ";
  cout << "|";
  for (int i=r; i<=end; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void printMerge(int left,int r,int right){
  cout << "merge = ";
  for (int i=left; i<r; i++)
    cout << arr[i] << " ";
  cout << "|" << arr[r] << "|";
  for (int i=r+1; i<=right; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void quickSort(int left, int right){
  if (left >= right) return;
  int p = left;
  int l=left, r=right;

  while(l <= r){
    while(arr[l] <= arr[p] && l <= right) l++;
    while(arr[r] >= arr[p] && r > left) r--;

    if (l <= r) swap(arr[l], arr[r]);
  }
  print(p,l,right);
  swap(arr[r], arr[p]);
  
  quickSort(left, r-1);
  printMerge(left, r, right);
  quickSort(r+1, right);
  printMerge(left, r, right);
}


int main(){
  ifstream file;
  file.open("input.txt");

  int n;
  file >> n;
  arr = new int[n];
  for (int i=0; i<n; i++){
    file >> arr[i];
  }

  quickSort(0,n-1);

  for (int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
}