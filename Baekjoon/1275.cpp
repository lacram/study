#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'
typedef long long ll;

using namespace std;

int n,m,k;
vector<ll> arr;
vector<ll> segmentTree;

ll makeST(int node, int srt, int end){
  if (srt == end) return segmentTree[node] = arr[srt];

  int mid = (srt+end)/2;
  ll leftRes = makeST(node*2,srt,mid);
  ll rightRes = makeST(node*2+1,mid+1,end);

  return segmentTree[node] = leftRes + rightRes;
}

ll getSum(int node, int nsrt, int nend, int left, int right){
  if (right < nsrt || left > nend) return 0;
  if (left <= nsrt && nend <= right) return segmentTree[node];

  int mid = (nsrt+nend)/2;
  ll leftRes = getSum(node*2,nsrt,mid,left,right);
  ll rightRes = getSum(node*2+1,mid+1,nend,left,right);

  return leftRes + rightRes;
}

void update(int node, int srt, int end, int idx, ll dif){
  if (idx < srt || idx > end) return;

  segmentTree[node] += dif;

  if (srt == end) return;

  int mid = (srt+end)/2;

  update(node*2,srt,mid,idx,dif);
  update(node*2+1,mid+1,end,idx,dif);
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> m;

  arr.resize(n);
  segmentTree.resize(n*4);

  for (int i=0; i<n; i++){
    cin >> arr[i];
  }

  makeST(1,0,n-1);

  for (int i=0; i<m; i++){
    int x,y,a,b;

    cin >> x >> y >> a >> b;
    x--;y--;a--;

    if (x <= y) cout << getSum(1,0,n-1,x,y) << endl;
    else cout << getSum(1,0,n-1,y,x) << endl;

    update(1,0,n-1,a,b-arr[a]);
    arr[a] = b;
  }
}