#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <stack>
#define endl '\n'

using namespace std;

int n;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  while (n--){
    string a,b;
    cin >> a >> b;

    stack<int> st;
    vector<int> va;
    vector<int> vb;

    for (int i=0; i<a.length(); i++){
      if (a[i] == '0') st.push(i);
      else {
        va.push_back(i-st.top());
        st.pop();
      }
    }

    for (int i=0; i<b.length(); i++){
      if (b[i] == '0') st.push(i);
      else {
        vb.push_back(i-st.top());
        st.pop();
      }
    }

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    cout << (va == vb) << endl;
  }

}