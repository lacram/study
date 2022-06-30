#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#define endl '\n'
#define INF 2000000000

using namespace std;

int compare(string str1, string str2){
  int pos = 0;
  int len = str1.size();

  while(str1[pos] == str2[pos])
    pos++;
  pos++;
  
  pos = min(pos, len);
  return pos;
}

int solution(vector<string> words) {
  sort(words.begin(), words.end());
  int ans = 0;

  for (int i=0; i<words.size(); i++){
    int tmp = 0;

    if (i != words.size()-1){
      tmp = max(tmp,compare(words[i], words[i+1]));
    }

    if (i != 0){
      tmp = max(tmp,compare(words[i], words[i-1]));
    }

    ans += tmp;
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution({"go","gone","guild"});

}