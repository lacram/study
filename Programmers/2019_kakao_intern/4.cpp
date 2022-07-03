#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#define endl '\n'

using namespace std;

unordered_map<long long, long long> parent;

// map은 key가 없을시 0 뱉음
long long find(long long u){
  if (parent[u] == 0) return parent[u] = u;
  return parent[u] = find(parent[u]);
}

vector<long long> solution(long long k, vector<long long> room_number) {

  vector<long long> res;
  for (int i=0; i<room_number.size(); i++){
    long long want = room_number[i];
    long long get = find(want);
    res.push_back(get);
    parent[get] = get+1;
  }
  return res;
}