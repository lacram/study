#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#define endl '\n'

using namespace std;

int n;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    int n = id_list.size();
    
    // 이름과 idx연결
    map<string,int> match;
    // 유저별 신고한 유저들
    vector<set<int>> reporting(n);
    // 유저별 신고당한 횟수
    vector<int> reported(n);
    
    int idx = 0;
    for (auto id : id_list){
        match[id] = idx++;
    }
    
    for (auto r : report){
        string str = r;
        string buffer;
        vector<int> tmp;
        
        istringstream ss(str);

        while (getline(ss, buffer, ' ')){
            tmp.push_back(match[buffer]);
        }
        // tmp[0]가 tmp[1] 신고
        reporting[tmp[0]].insert(tmp[1]);
    }

    for (auto reporting_id: reporting){
      for (auto reported_id : reporting_id)
        reported[reported_id]++;
    }
    
    for (auto id : id_list){
        int ans = 0;
        for (auto reported_id : reporting[match[id]])
            if (reported[reported_id] >= k)
                ans++;
        answer.push_back(ans);
    }
    
    return answer;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  vector<string> id_list = {"muzi", "frodo", "apeach", "neo"};
  vector<string> report = {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"};
  int k = 2;

  for (auto ans : solution(id_list,report,k))
    cout << ans;
}