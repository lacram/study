#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

int n, time, m;
int runtime[50];
double prob[50][50];


double solve(int rtime, int now, int fav){
  if (rtime <= -1) 
    return fav == now ? 1 : 0;

  double ret=0;
  for (int i=0; i<n; i++){
    ret += solve(rtime-runtime[i],i,fav) * prob[now][i];
  }
  
  return ret;
}


int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  ifstream cin;
  cin.open("test.txt");

  int test;
  cin >> test;

  while (test--){
    cin >> n >> time >> m;

    for (int i=0; i<n; i++){
      cin >> runtime[i];
    }

    for (int i=0; i<n; i++)
      for (int j=0; j<n; j++)
        cin >> prob[i][j];
    
    for (int i=0; i<n; i++){
      int a;
      cin >> a;
      cout << solve(time-runtime[0], 0, a) << " "; 
    }

    cout << endl;
    
  }
  
}