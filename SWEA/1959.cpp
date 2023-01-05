#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
// #include<fstream>

using namespace std;

int n,m;
vector<int> arr1;
vector<int> arr2;

int getAns(vector<int> shortArr, vector<int> longArr) {
    int ans = 0;
    // 시작위치
    for (int idx=0; idx+shortArr.size()<=longArr.size(); idx++) {
        int tmp = 0;
        for (int i=0; i<shortArr.size(); i++) {
            tmp += shortArr[i] * longArr[idx+i];
        }
        ans = max(ans,tmp);
    }
    return ans;
}

// 길이가 짧은 배열을 움직이기
int solution() {
    if (n > m) return getAns(arr2,arr1);
    else return getAns(arr1,arr2);
}

int main()
{
	// ifstream cin;
	// cin.open("input.txt");

	int t;
	cin >> t;
	for (int k = 1; k <= t; k++) {
        cin >> n >> m;

        arr1.clear();
        arr2.clear();

        for (int i=0; i<n; i++) {
            int a;
            cin >> a;
            arr1.push_back(a);
        }

        for (int j=0; j<m; j++) {
            int a;
            cin >> a;
            arr2.push_back(a);
        }
		
		cout << "#" << k << " " << solution() << endl;
		
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

