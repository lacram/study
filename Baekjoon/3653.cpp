#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,m,test,num,pos;
vector<int> arr;
vector<int> segmentTree;
vector<int> position;

int makeST(int node, int srt, int end){
  if (srt == end) return segmentTree[node] = position[srt];

  int mid = (srt+end)/2;
  int leftRet = makeST(node*2,srt,mid);
  int rightRet = makeST(node*2+1,mid+1,end);

  return segmentTree[node] = leftRet + rightRet;
}

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

void solve(){
  int idx = arr[num];
  cout << getSum(1,0,n+m-1,0,idx-1) << " ";

  update(1,0,n+m-1,pos,1);
  update(1,0,n+m-1,idx,-1);
  arr[num] = pos--;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> test;

  while (test--){
    cin >> n >> m;

    arr.clear();
    segmentTree.clear();
    position.clear();
    arr.resize(n+1);
    segmentTree.resize((n+m)*4);
    position.resize(n+m);
    
    for (int i=1; i<=n; i++)
      arr[i] = m+i-1;
    for (int i=m; i<n+m; i++)
      position[i] = 1;

    makeST(1,0,n+m-1);
    pos = m-1;

    for (int i=0; i<m; i++){
      cin >> num; 
      solve();
    }
    
    cout << endl;
  }
}