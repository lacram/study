#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <set>

using namespace std;

int n,k;
vector<pair<int,int>> arr;
multiset<int> bag;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n >> k;

  for (int i=0; i<n; i++){
    int a,b;
    cin >> a >> b;
    // 가치 기준으로 정렬하기 위해
    arr.push_back(make_pair(b,a));
  }
  
  for (int i=0; i<k; i++){
    int a;
    cin >> a;
    bag.insert(a);
  }
  
  sort(arr.begin(), arr.end(), greater<>());

  long long ans = 0;

  for (int i=0; i<n; i++){
    int jewelryW = arr[i].second;
    // bagIdx : 보석을 담을 수 있는 가방의 최소 인덱스
    auto bagIdx = bag.lower_bound(jewelryW);
    if (bagIdx != bag.end()){
      bag.erase(bagIdx);
      ans += arr[i].first;
      k--;
    }
  }
  
  cout << ans;
}