#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define endl '\n'
#define INF 2000000000
typedef long long ll;

using namespace std;

multimap<ll,ll> inviting;
map<ll,int> invitingCnt;
map<ll,int> score;
set<ll> member;
map<ll,int> order;

void getScore(ll member, ll invited, int depth) {
  if (depth == 0) {
    score[member] += invitingCnt[invited]*10;
  } else if (depth == 1) {
    score[member] += invitingCnt[invited]*3;
  } else if (depth == 2) {
    score[member] += invitingCnt[invited];
  } else {
    return;
  }

  multimap<ll,ll>::iterator iter;
  for (iter=inviting.lower_bound(invited); iter!=inviting.upper_bound(invited); iter++) {
    ll next = iter->second;
    getScore(member,next,depth+1);
  }
}

bool cmp(const pair<ll,int>& a, const pair<ll,int>& b) {
	if (a.second == b.second) return order[a.first] < order[b.first];
	return a.second > b.second;
}

vector<long long> solution(vector<vector<long long>> invitationPairs) {
  
  int time = 0;
  for (auto invitation : invitationPairs) {
    inviting.insert({invitation[0], invitation[1]});
    member.insert(invitation[0]);
    member.insert(invitation[1]);
    order[invitation[0]] = time++;
  }
  
  for (auto m : member) {
    invitingCnt[m] = inviting.count(m);
  }

  for (auto m : member) {
    getScore(m,m,0);
  }

  vector<pair<ll,int>> v(score.begin(), score.end());

  sort(v.begin(), v.end(), cmp);

  vector<ll> ans = {};
  for (int i=0; i<3 && i<v.size(); i++) {
    // 최소 한명이상 추천해야됨
    if (v[i].second != 0) {
      ans.push_back(v[i].first);
    }
  }

  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution({{1, 2}});

}