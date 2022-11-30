#include <iostream>

using namespace std;

int *arr;
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int left, int right){
  if(left>=right) return;
  int piv = left;
  int l=left, r = right;
  int tmp;
  while(l < r){
    while (arr[piv] > arr[l] && l <= right) l++;
    while (arr[piv] < arr[r] && r > left) r--;
    
    if(l > r) 
      swap(arr[piv], arr[r]);
    else swap(arr[l], arr[r]);
  }

  quickSort(left, r-1);
  quickSort(r+1, right);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, pos;
  cin >> n >> pos;
  arr = new int[n];
  for (int i=0; i<n; i++)
    cin >> arr[i];
  quickSort(0,n-1);
  
  cout << arr[pos-1];
  
}