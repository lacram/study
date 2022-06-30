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

vector<int> score[3][2][2][2];

vector<int> solution(vector<string> info, vector<string> query) {
  map<string,int> m = {
    {"cpp", 0}, 
    {"java", 1},
    {"python", 2},

    {"backend", 0}, 
    {"frontend", 1}, 

    {"junior", 0}, 
    {"senior", 1}, 

    {"chicken", 0}, 
    {"pizza", 1}, 
  };

  for (auto in : info ){
    int pos = 0;
    vector<string> w;

    while ((pos = in.find(" ")) != string::npos){
      w.push_back(in.substr(0, pos));
      in.erase(0, pos + 1);
    }
    score[m[w[0]]][m[w[1]]][m[w[2]]][m[w[3]]].push_back(stoi(in));
  }

  for (int i=0; i<3; i++)
    for (int j=0; j<2; j++)
      for (int k=0; k<2; k++)
        for (int l=0; l<2; l++)
          sort(score[i][j][k][l].begin(), score[i][j][k][l].end());

  vector<int> ans;

  for (auto q : query){
    int pos = 0;
    vector<string> w;

    while ((pos = q.find(" ")) != string::npos) {
      string str = q.substr(0,pos);
      if (str != "and") w.push_back(str);
      q.erase(0,pos+1);
    }

    int cnt = 0;
    int sc = stoi(q);

    for (int i=0; i<3; i++){
      if (w[0] != "-" && m[w[0]] != i) continue;

      for (int j=0; j<2; j++){
       if (w[1] != "-" && m[w[1]] != j) continue;

        for (int k=0; k<2; k++){
          if (w[2] != "-" && m[w[2]] != k) continue;

          for (int l=0; l<2; l++){
            if (w[3] != "-" && m[w[3]] != l) continue;

            cnt += score[i][j][k][l].end() - lower_bound(score[i][j][k][l].begin(), score[i][j][k][l].end(), sc);
          }
        }
      }
    }

    ans.push_back(cnt);

  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution({"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"} ,    {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"} );

}