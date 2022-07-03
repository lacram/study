#include <iostream>
#include <cstring>
using namespace std;

int cnt=0;
int isFriend[11][11];
bool isPair[11];

void findPair(int num){
  int sum=0;
  for(int k=0; k<num; k++){
    sum += isPair[k];
  }
  if (sum == num){
    cnt++;
    return;
  }
  for(int i=0; i<num; i++){
    for(int j=0; j<num; j++){
      if(!isPair[i] && !isPair[j] && isFriend[i][j]){
        isPair[i] = isPair[j] = true;
        findPair(num);
        isPair[i] = isPair[j] = false;
      }   
    }
  }
}

int main(){
  int test, num, pair;
  
  cin >> test;

  while (test--){
    cnt = 0;
    cin >> num >> pair;

    memset(isFriend, 0, sizeof(isFriend));
    memset(isPair, 0, sizeof(isPair));

    while(pair--){
      int x,y;
      cin >> x >> y;
      isFriend[x][y] = 1;
    } 

    findPair(num);
    int i = num / 2;
    while (i){
      cnt /= i;
      i--;
    }
    
    cout << cnt << endl;
  }
}


