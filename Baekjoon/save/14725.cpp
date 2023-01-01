#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <map>
#define endl '\n'

using namespace std;

struct Node{
	map<string, Node> child;
};

void insert(Node &v, vector<string> &arr, int idx){
	if(idx == arr.size()) return;

	if(!v.child.count(arr[idx])) v.child[arr[idx]] = Node();
  
	insert(v.child[arr[idx]], arr, idx+1);
}

void dfs(Node &v, int depth){
	for(auto i : v.child){
		for(int j=0; j<depth; j++) 
      cout << "--";
		cout << i.first << "\n";

		dfs(i.second, depth+1);
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int t; 
  cin >> t;

  Node root;

	while(t--){
		int n; 
    cin >> n;

		vector<string> v(n);

		for(int i=0; i<n; i++) 
      cin >> v[i];
		insert(root, v, 0);
	}

	dfs(root,0);
}