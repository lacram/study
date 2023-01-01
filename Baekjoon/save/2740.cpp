#include <iostream>
#include <cstring>
using namespace std;


int main(){
  int ah,aw,bh,bw;

  int a[100][100];
  int b[100][100];
  int c[100][100];
  memset(c, 0, sizeof(c));
  cin >> ah >> aw;
  for (int i=0; i<ah; i++)
    for (int j=0; j<aw; j++)
      cin >> a[i][j];
      
  cin >> bh >> bw;
  for (int i=0; i<bh; i++)
    for (int j=0; j<bw; j++)
      cin >> b[i][j];    

  // 행렬 곱셈 C의 i행 j열의 값 = A의 i행의 값 × B의 j열의 값
  for (int i=0; i<ah; i++){
    for (int j=0; j<bw; j++){
      for (int k=0; k<aw; k++)
        c[i][j] += a[i][k]*b[k][j];
      cout << c[i][j] << " "; 
    }
    cout << endl;
  }
    
      
  
    
}