#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#define endl '\n'

using namespace std;

int n, v, e;
int edge[1001][1001];
int color[1001];
bool ans;

bool promissing(int node){
  for (int i=1; i<node; i++)
    if (edge[i][node] && color[i] == color[node])
      return false;
  return true;
}

void solve(int node){
  if (promissing(node)){
    if (node == v)
      ans = true;
    else{
      for (int i=0; i<2; i++){
        color[node+1] = i;
        solve(node+1);
      }
    }
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin;
  cin.open("input.txt");

  cin >> n;

  for (int i=0; i<n; i++){
    cin >> v >> e;

    memset(color, 0, sizeof(color));
    memset(edge, 0, sizeof(edge));

    for (int i=0; i<e; i++){
      int a, b;
      cin >> a >> b;
      edge[a][b] = 1;
      edge[b][a] = 1;
    }
    
    ans = false;

    solve(0);

    if (ans) cout << "possible" << endl;
    else cout << "impossible" << endl;
  }

  
}