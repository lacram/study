#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;

bool canGetAll(vector<int> dist, int now) {

  int idx = upper_bound(dist.begin(), dist.end(), now)-dist.begin();
  int lo = idx-1; // 가장 가까운 왼쪽 보석의 idx
  int hi = idx; // 가장 가까운 오른쪽 보석의 idx

  while (1) {
    if (now-dist[lo] < dist[hi]-now) {
      now = dist[lo];
      lo--;
      if (lo < 0) {
        return true;
      }
    } else if (now-dist[lo] > dist[hi]-now) {
      now = dist[hi];
      hi++;
      if (hi >= n) {
        return true;
      }
    } else {
      return false;
    }
  }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 sample_input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 sample_input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 sample_input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
  freopen("input.txt", "r", stdin);


	/*
	   아래 코드는 입출력수행 프로세스 속도를 향상시키기 위한 명령어입니다.
	   아래 코드가 실행될 경우 scanf와 cin을 혼용해서 사용할 시 테스트 케이스가 정상적으로 입력되지 않을 수 있으니 유의하십시오.
	*/
	std::ios::sync_with_stdio(false);

	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{

    cin >> n >> m;

    vector<int> v;
    for (int i=0; i<n; i++) {
      int a;
      cin >> a;
      v.push_back(a);
    }
		
    vector<int> dist;
    for (int i=0; i<v.size(); i++) {
      if (v[i]) {
        dist.push_back(i+1);
      }
    }

    int k = 0;
    while (1) {
      if (canGetAll(dist, m+k)) {
        break;
      }
      if (canGetAll(dist, m-k)) {
        break;
      }
      k++;
    }
		
		// 표준출력(화면)으로 답안을 출력합니다.
		cout << "#" << test_case << " " << k << endl;
	}

	return 0; // 정상종료시 반드시 0을 리턴해야 합니다.
}
