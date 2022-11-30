#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

int n,k;
vector<int> arr;
vector<int> segmentTree;

int makeST(int node, int srt, int end){
  if (srt == end) return segmentTree[node] = arr[srt];

  int mid = (srt+end)/2;
  int leftRes = makeST(node*2,srt,mid);
  int rightRes = makeST(node*2+1,mid+1,end);

  return segmentTree[node] = leftRes*rightRes;
}

int getMul(int node, int nsrt, int nend, int left, int right){
  if (nsrt > right || nend < left) return 1;
  if (left <= nsrt && nend <= right) return segmentTree[node];

  int mid = (nsrt+nend)/2;
  int leftRes = getMul(node*2,nsrt,mid,left,right);
  int rightRes = getMul(node*2+1,mid+1,nend,left,right);

  return leftRes*rightRes;
}

int update(int node, int srt, int end, int idx, int value){
  if (idx < srt || idx > end) return segmentTree[node];

  if (srt == end) {
    if (segmentTree[node] == 0) return segmentTree[node] = value;
    return segmentTree[node] *= value;
  }

  int mid = (srt+end)/2;
  int leftRes = update(node*2,srt,mid,idx,value);
  int rightRes = update(node*2+1,mid+1,end,idx,value); 

  return segmentTree[node] = leftRes*rightRes;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  while (cin >> n >> k){
    arr.clear();
    segmentTree.clear();
    arr.resize(n);
    segmentTree.resize(n*4);

    for (int i=0; i<n; i++){
      int num;
      cin >> num;

      if (num > 0) arr[i] = 1;
      else if (num < 0) arr[i] = -1;
      else arr[i] = 0;
    }

    makeST(1,0,n-1);
    
    char a;
    int b,c;

    for (int i=0; i<k; i++){
      cin >> a >> b >> c;
      b--;

      if (a == 'C'){
        if (c == 0) {
          update(1,0,n-1,b,0);
          arr[b] = 0;
        }
        else if (arr[b] == 0) {
          if (c > 0) update(1,0,n-1,b,1);
          else update(1,0,n-1,b,-1);
          arr[b] = c;
        }
        else{
          if ((c * arr[b] < 0)){
            update(1,0,n-1,b,-1);
          }
          arr[b] = c;
        }
      }
      if (a == 'P'){
        c--;
        int ans = getMul(1,0,n-1,b,c);

        if (ans > 0) cout << '+';
        else if (ans < 0) cout << '-';
        else cout << '0';
      }
    }
    cout << endl;
  }

}