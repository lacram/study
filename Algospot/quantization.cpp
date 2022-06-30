#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

int *arr;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  // ifstream cin;
  // cin.open("test.txt");

  int test, len, n;
  cin >> test;

  while (test--){
    cin >> len >> n;
    
    arr = new int[len];
    for (int i=0; i<len; i++){
      cin >> arr[i];
    }

    sort(arr, arr+len);

    vector<pair<int,int>> v;

    for (int i=0; i<len-1; i++){
      v.push_back(pair<int,int>(arr[i+1]-arr[i],i+1));
    }

    sort(v.begin(), v.end());

    vector<int> a;
    a.push_back(0);
    a.push_back(len);

    n-=1;
    while (n--){
      a.push_back(v.back().second);
      v.pop_back();
    }
    sort(a.begin(), a.end());
    int ret=0;
    for(int i=0; i<a.size()-1; i++){
      float sum=0;
      for(int j=a[i]; j<a[i+1]; j++)
        sum += arr[j];
      int avg = floor(sum/(a[i+1]-a[i])+0.5);
      for(int j=a[i]; j<a[i+1]; j++)
        ret += pow(abs(avg-arr[j]),2);
    }
    cout << ret << endl;
  }
  
  
}