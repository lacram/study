#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n;
vector<int> height;
vector<int> segmentTree;

int makeST(int node, int srt, int end){
  if (srt == end) return segmentTree[node] = srt;
  
  int mid = (srt+end)/2;
  int leftRes = makeST(node*2,srt,mid);
  int rightRes = makeST(node*2+1,mid+1,end);

  if (height[leftRes] < height[rightRes]) return segmentTree[node] = leftRes;
  else return segmentTree[node] = rightRes;
}

int getMin(int node, int srt, int end, int left, int right){
  if (srt > right || end < left) return left;
  if (left <= srt && end <= right) return segmentTree[node];

  int mid = (srt+end)/2;
  int leftRes = getMin(node*2,srt,mid,left,right);
  int rightRes = getMin(node*2+1,mid+1,end,left,right);

  if (height[leftRes] < height[rightRes]) return leftRes;
  else return rightRes;
}

long long solve(int left, int right){
  if (left == right) return height[left];

  int idx = getMin(1,0,n-1,left,right);
  long long ret = (long long) height[idx]*(right-left+1);

  if (idx - 1 >= left){
    ret = max(ret, solve(left,idx-1));
  }
  if (idx+1 <= right) {
    ret = max(ret, solve(idx+1,right));
  }

  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  while (cin >> n) {
    if (!n) break;
    height.resize(n);
    segmentTree.clear();
    segmentTree.resize(n*4);

    for (int i=0; i<n; i++)
      cin >> height[i];
    
    makeST(1,0,n-1);

    cout << solve(0,n-1) << endl;
  }

}