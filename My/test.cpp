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

struct Trie{
  Trie *child[26];
  int childNum;

  Trie() {
    memset(child, 0, sizeof(child));
    childNum = 0;
  }

  Trie* insert(char* pstr) {
   if (*pstr == 0) return this;
   else {
      this->childNum++;
      int next = *pstr - 'a';
      if (child[next] == NULL) child[next] = new Trie();

      return child[next]->insert(pstr+1);
    }
  }

  Trie* find(char* pstr) {
    if (*pstr == 0) return this;
    int next = *pstr - 'a';
    if (child[next] == NULL) return NULL;
    return child[next]->find(pstr+1);
  }

};

int getPos(string str) {
  for (int i=0; i<str.size(); i++){
    if (str[i] == '?') return i;
  }
}

int solution(vector<string> words, vector<string> queries) {
  
  Trie trie[10001],Rtrie[10001];
  vector<int> ans;

  for (auto word : words) {
    trie[word.size()].insert(&word[0]);
    reverse(word.begin(), word.end());
    trie[word.size()].insert(&word[0]);
  }

  for (auto query : queries) {
    int pos = 0;
    int len = query.size();
    if (query[0] == '?') reverse(query.begin(), query.end());

    pos = getPos(query);
    query = query.substr(0,pos);
    Trie* ptrie = trie[len].find(&query[0]);
    //if (pos == 0) ptrie = &trie[len];

    if (ptrie != NULL) ans.push_back(ptrie->childNum);
    else ans.push_back(0);
  }

  return 1;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  solution({"frodo", "front", "frost", "frozen", "frame", "kakao"}, {"fro??", "?????", "fr???", "fro???", "pro?"});

}