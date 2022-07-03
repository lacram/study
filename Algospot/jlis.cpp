#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

int a[5];
int b[3];
int na,nb;


int solve(int apos, int bpos){
  int ret = 2;
  
  for (int i=apos+1; i<na; i++){
    if (a[apos] < a[i] || apos == -1)
      ret = max(ret, solve(i, bpos)+1);
  }
  for (int i=bpos+1; i<nb; i++)
    if (b[bpos] < b[i] || bpos == -1)
      ret = max(ret, solve(apos, i)+1);

  return ret;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  ifstream file;
  file.open("test.txt");

  int test;
  file >> test;

  while (test--){
    file >> na >> nb;

    for (int i=0; i<na; i++){
      file >> a[i];
    }
    for (int i=0; i<nb; i++){
      file >> b[i];
    }

    cout << solve(-1,-1)-2 << endl;
  }
  
}