#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'
#define max 1000000

using namespace std;

int n,ranking;
vector<int> segmentTree(max*4);
vector<int> arr(max+1);

int getSum(int node, int srt, int end, int left, int right){
  if (srt > right || end < left) return 0;
  if (left <= srt && end <= right) return segmentTree[node];

  int mid = (srt+end)/2;
  int leftRet = getSum(node*2,srt,mid,left,right);
  int rightRet = getSum(node*2+1,mid+1,end,left,right);

  return leftRet + rightRet;
}

void update(int node, int srt, int end, int idx, int dif){
  if (srt > idx || end < idx) return;

  segmentTree[node] += dif;

  if (srt == end) return;

  int mid = (srt+end)/2;
  update(node*2,srt,mid,idx,dif);
  update(node*2+1,mid+1,end,idx,dif);
}

bool decision(int idx){
  return getSum(1,0,max,1,idx) >= ranking;
}

int solve(){
  int lo = 0;
  int hi = 1000000;

  while (lo <= hi){
    int mid = (lo+hi)/2;

    if (decision(mid)) hi = mid-1;
    else lo = mid+1;
  }

  return lo;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    int k,a,b;
    cin >> k;

    if (k == 1) {
      cin >> ranking;
      int num = solve();
      cout << num << endl;
      arr[num]--;
      update(1,0,max,num,-1);
    }
    if (k == 2){
      cin >> a >> b;
      update(1,0,max,a,b);
      arr[a] = b;
    }
  }

}