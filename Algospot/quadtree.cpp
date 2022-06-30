#include <iostream>
#include <vector>
using namespace std;

string::iterator iter;

string reverse(){
  iter++;
  if (*iter == 'b' || *iter == 'w'){
    return string(1, *iter);
  }
  string lu = reverse();
  string ru = reverse();
  string ld = reverse();
  string rd = reverse();

  return string("x") + ld + rd + lu + ru;
}

int main(){
  int test;
  cin >> test;

  while(test--){
    string str;
    cin >> str;

    iter = str.begin()-1;
    cout << reverse() << endl;
  }
}