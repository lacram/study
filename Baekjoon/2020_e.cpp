#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
int n;

void func(string mp, int x){

	int p = 0;
	ll t = 0;

	//이동 방향 0 동쪽, 1 서쪽
	int dir = 0;

	bool rightr = false; 
	bool leftr = false;

	int cur = x;
	int right = 0;
	int left = 0;

	while (true) {
		//오른쪽으로 이동
		if (dir == 0) {
			++cur; ++right; ++t;

			//지도 탈출
			if (cur > n) break;

      // 빈공간 아닐때
			if (mp[cur] != '.') {
				if (mp[cur] == 'P') {
					++p;
					mp[cur] = '.';
				}
				if (mp[cur] == 'R') {
					// 오른쪽 돌 만남
					rightr = true;
					//바위 두번 만남
					if (leftr) {
						t = -1;
						break;
					}
				}
				//왼쪽에 돌 방문한 적 있다면 돌 찍고 돌아오기
				if (leftr) {
					t += left;
					t += right;
				}
				//방향 바꾸고 왼쪽 탐색 안한 좌표로
				else {
					dir = 1;
					cur = x - left;
					t += left;
					t += right;
				}
			}
		}
		//왼쪽으로 이동
		else {
			--cur; ++left; ++t;

			//지도 탈출
			if (cur < 1) break;

			if (mp[cur] != '.') {
				if (mp[cur] == 'P') {
					++p;
					mp[cur] = '.';
				}
				if (mp[cur] == 'R') {
					leftr = true;
					//바위 두번 만남
					if (rightr) {
						t = -1;
						break;
					}
				}
				//오른쪽에 돌 방문한 적 있다면 돌 찍고 돌아오기
				if (rightr) {
					t += left;
					t += right;
				}
				//방향 바꾸고 오른쪽 탐색 안한 좌표로
				else {
					dir = 0;
					cur = x + right;
					t += left;
					t += right;
				}
			}
		}
	}

	cout << p << " " << t << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	int q;
	cin >> q;

	//지도
	string mp;
	cin >> mp;

  vector<int> rock;
  for (int i=0; i<mp.length(); i++)
    if (mp[i] == 'R')
      rock.push_back(i+1);

	//위치 1부터 시작할 수 있도록 맨 앞에 . 추가
	mp = "." + mp;

	while (q--) {
		int x;
		cin >> x;

    if (x > rock[0] && x < rock[rock.size()-1]){
      cout << 0 << " " << -1 << endl;
      continue;
    }

		func(mp, x);
	}

	return 0;
}