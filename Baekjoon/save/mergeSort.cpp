#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int arr[9];
int arrt[9];

void merge(int left, int right){
  int mid = (left+right)/2;
  int l=left, r=mid+1, pos=left;

  while (l<=mid && r<=right){
    if(arr[l] < arr[r]){
      arrt[pos++] = arr[l++];
    }
    else{
      arrt[pos++] = arr[r++];
    }
  }

  int k = r > right ? l : r;
  while (pos <= right){
    arrt[pos++] = arr[k++];
  }
  for (int i=left; i<=right; i++){
    arr[i] = arrt[i];
  }
}

void mergeSort(int left, int right){
  if (left >= right) return;
  
  int mid = (left+right)/2;

  mergeSort(left, mid);
  mergeSort(mid+1, right);
  merge(left, right);
}


int main(){
  ifstream file;
  file.open("test1.txt");

  int n;
  file >> n;
  //arr = new int[n];
  for (int i=0; i<n; i++){
    file >> arr[i];
  }
  for (int i=0; i<n; i++){
    cout << arr[i] << " ";
  }

  mergeSort(0,n-1);

  for (int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
}