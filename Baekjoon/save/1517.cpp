#include <iostream>

using namespace std;

long long cnt=0;
int n[1000000];
int *tmpn;

void merge(int left, int right,int mid){
  int l=left, r=mid+1 , pos=left;
  while(l <= mid && r <= right){
    if(n[l] > n[r]){
      tmpn[pos++] = n[r++];
      cnt += r-pos;
    }
    else{
      tmpn[pos++] = n[l++];
    }
  }
  // 한쪽이 먼저 끝날시
  int tmp = r>right ? l : r;
  while(pos <= right){
    tmpn[pos++] = n[tmp++];
  }
  
  for (int i=left; i<=right; i++)
    n[i] = tmpn[i];
}

void mergeSort(int left, int right){
  if (left == right) return;
  int mid = (left+right)/2;
  mergeSort(left,mid);
  mergeSort(mid+1, right);
  merge(left,right,mid);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int num;
  cin >> num;
  tmpn = new int[num];
  for (int i=0; i<num; i++)
    cin >> n[i];
  mergeSort(0,num-1);

  cout << cnt;
  
}