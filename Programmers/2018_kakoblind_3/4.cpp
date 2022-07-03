#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <string>
#define endl '\n'
#define INF 2000000000

using namespace std;

vector<pair<pair<string,int>, pair<int,string>>> v;
map<pair<pair<string,int>, pair<int,string>>, string> m;

vector<string> solution(vector<string> files) {
  int idx = 0;
  for (auto file : files){
    string ufile = file;
    transform(file.begin(), file.end(), ufile.begin(), ::toupper);

    for (int i=0; i<file.size(); i++){
      if ('0' <= file[i] && file[i] <= '9'){
        string num = "";
        int pos = i;

        while ('0' <= file[pos] && file[pos] <= '9')
          num.push_back(file[pos++]);

        pair<string,int> p = {ufile.substr(0,i), stoi(num)};
        v.push_back({p,{idx,file.substr(pos)}});
        m[{p,{idx,file.substr(pos)}}] = file;
        break;
      }
    }
    idx++;
  }

  sort(v.begin(), v.end());

  vector<string> ans;

  for (auto a: v){
    ans.push_back(m[a]);
  }  
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  vector<string> ans =  solution({"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"});
  for (auto a : ans)
    cout << a << endl;
}