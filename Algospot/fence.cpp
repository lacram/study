#include <iostream>
#include <vector>
using namespace std;

vector <int> height;

int getSquare(int left, int right){
  // 기저사례
  if (right == left ) return height[left];

  int mid = (left + right) / 2;
  int ret = 0;
  
  ret = max(getSquare(left, mid), getSquare(mid+1, right));
  
  
  // 중간 최대
  int l=mid,r=mid+1;
  int minh = min(height[mid], height[mid+1]);
  ret = max(ret, 2*minh);
  while (l>left || r < right){
    if((height[l-1] > height[r+1] || r == right) && l > left){
      l--;
      minh = min(height[l], minh);
    }
    else{
      r++;
      minh = min(height[r], minh);
    }
    ret = max(ret, (r-l+1)*minh);
  }
  return ret;
}


int main(){
  int test;
  cin >> test;
  while (test--){
    int n;
    cin >> n;
    int a;
    for (int i=0; i<n; i++){
      cin >> a;
      height.push_back(a);
    }
    
    cout << getSquare(0,n-1) << endl;
    height.clear();
  }
  
}