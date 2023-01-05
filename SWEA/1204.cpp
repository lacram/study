#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
// #include<fstream>

using namespace std;

int n,m;
int arr[1000];

bool compare(pair<int,int> a, pair<int,int> b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

int solution() {
    map<int,int> record;

    for (int i=0; i<1000; i++) {
        record[arr[i]]++;
    }

    vector<pair<int,int>> v(record.begin(), record.end());
    sort(v.begin(), v.end(), compare);

    return v.front().first;
}

int main()
{
	// ifstream cin;
	// cin.open("input.txt");

	int t;
	cin >> t;
	for (int k = 1; k <= t; k++) {
        int test;
        cin >> test;

        for (int i=0; i<1000; i++) {
            cin >> arr[i];
        }
        
		cout << "#" << k << " " << solution() << endl;
		
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

