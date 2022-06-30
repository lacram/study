#include <string>
#include <vector>

using namespace std;

bool decision(vector<int> stones, int k, int num){
  int cnt = 0;
  for (int i=0; i<stones.size(); i++){
    if (stones[i] >= num) {
      cnt = 0;
    }
    else {
      cnt++;
        if (cnt == k) {
          return false;
        }
    }
  }
  return true;
}

int solution(vector<int> stones, int k) {
  int lo = 0;
  int hi = 200000001;

  while (lo <= hi){
    int mid = (lo+hi)/2;
    if (decision(stones, k, mid)) lo = mid+1;
    else hi = mid-1;
  }

  return hi;
}