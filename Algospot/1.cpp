#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

int overlap(string s1, string s2)
{
	for (int len = min(s1.size(), s2.size()); len > 0; len--) {
    string a = s1.substr(s1.size() - len);
    string b = s2.substr(0, len);
		if (a== b) {
			return len;
		}
  }
	return 0;
}
int main(){
  cout << overlap("125678","67841");
  
}

