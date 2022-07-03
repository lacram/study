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

struct linkedList{
  linkedList* prev;
  linkedList* next;
  int value;
};

string solution(int n, int k, vector<string> cmd) {
  linkedList* ll = new linkedList[n];

  for (int i=0; i<n; i++) {
    ll[i].prev = &ll[(i+n-1)%n];
    ll[i].next = &ll[(i+n+1)%n];
    ll[i].value = i;
  }

  stack<pair<int,linkedList*>> deleted;

  linkedList* now = &ll[0];
  int last = n-1;
  while (k--) now = now->next;

  for (auto str : cmd){
    if(str[0]=='U' || str[0]=='D'){
      int x = stoi(str.substr(2));
      if(str[0]=='U') while (x--) now = now->prev;
      else while (x--) now = now->next;
    }

    else if(str[0]=='C'){
      deleted.push({now->value, now});
      now->prev->next = now->next;
      now->next->prev = now->prev;
      if (now->value == last) {
        now = now->prev;
        last--;
      }
      else now = now->next;
    }
    
    else if(str[0]=='Z'){
      linkedList* rollback = deleted.top().second;
      if (rollback->value == last+1) last++;
      rollback->prev->next = rollback;
      rollback->next->prev = rollback;
      deleted.pop();
    }
  }
  string ans(n,'O');
  while (!deleted.empty()){
    int idx = deleted.top().first;
    ans[idx] = 'X';
    deleted.pop();
  }
  return ans;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cout << solution(8,7,{"C","Z","C","Z","C","Z","C","Z","C"});

}