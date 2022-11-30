#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
vector<int> a;

//연두의 데이터에 따른 조건
struct Rule {
   //비트 연산 종류
   char op;
   //비트 연산 대상
   int pos;
   //비트 연산 결과
   int res;

   Rule(char _op, int _pos, int _res) : op(_op), pos(_pos), res(_res){}
};

//rule[i]: i번째 자리가 만족해야하는 조건
vector<Rule> rule[50001];

void bfs() {

   vector<int> begin_seat;

   //begin_seat의 인덱스 1부터 시작하도록 맨 앞에 의미 없는 수 삽입
   begin_seat.push_back(-1);
   for (int i = 1; i <= N; ++i) {
      if (a[i] == 0) break;
      else begin_seat.push_back(a[i]);
   }

   queue<vector<int>> q;
   q.push(begin_seat);

   while (!q.empty()) {
      vector<int> cur_seat = q.front();
      q.pop();

      //아이를 앉혀야할 자리
      int cur = cur_seat.size();

      //N번째 자리까지 모두 아이를 앉힌 경우
      if (cur > N) {
         cout << 1 << "\n";
         for (int i = 1; i <= N ; ++i)
            cout << cur_seat[i] << " ";
         return;
      }

      //bfs에서 visited 배열을 이용하여 이미 방문했다면 건너뛰어야하는데
      //이 문제에서 visited를 어떻게 구현해야할 지 모르겠음
      //이 때문에 시간 초과가 발생하는 것 같다

      //다음 자리에 앉힐 아이의 나이가 정해진 경우
      if (a[cur] != 0) {
         //조건을 모두 만족하는지 확인
         bool flag = true;
         for (int i = 0; i < rule[cur].size(); ++i) {
            Rule cur_rule = rule[cur][i];

            if (cur_rule.op == '&') {
               if ((a[cur] & cur_seat[cur_rule.pos]) != cur_rule.res) {
                  flag = false;
                  break;
               }
            }
            else if (cur_rule.op == '|') {
               if ((a[cur] | cur_seat[cur_rule.pos]) != cur_rule.res) {
                  flag = false;
                  break;
               }
            }
         }

         //조건 모두 만족한다면 자리에 앉힌다
         if (flag) {
            vector<int> next_seat(cur_seat.begin(), cur_seat.end());
            next_seat.push_back(a[cur]);
            q.push(next_seat);
         }
         else {
            cout << 0;
            return;
         }
      }

      //다음 자리에 앉힐 아이의 나이가 정해지지 않은 경우
      else {
         for (int age = 8; age <= 19; ++age) {
            //조건을 모두 만족하는지 확인
            bool flag = true;
            for (int i = 0; i < rule[cur].size(); ++i) {
               Rule cur_rule = rule[cur][i];

               if (cur_rule.op == '&') {
                  if ((age & cur_seat[cur_rule.pos]) != cur_rule.res) {
                     flag = false;
                     break;
                  }
               }
               else if (cur_rule.op == '|') {
                  if ((age | cur_seat[cur_rule.pos]) != cur_rule.res) {
                     flag = false;
                     break;
                  }
               }
            }

            //조건 모두 만족한다면 자리에 앉힌다
            if (flag) {
              vector<int> next_seat(cur_seat.begin(), cur_seat.end());
              next_seat.push_back(age);
              q.push(next_seat);
            }
            else
               continue;
         }
      }

   }

   cout << 0;
   return;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   cin >> N;

   //a의 인덱스 1부터 시작하도록 맨 앞에 의미 없는 수 삽입
   a.push_back(-1);
   for (int i = 1; i <= N; ++i) {
      int input;
      cin >> input;
      a.push_back(input);
   }

   cin >> M;
   for (int i = 1; i <= M; ++i) {
      char op;
      int x, y, z;
      cin >> op >> x >> y >> z;

      if(x > y) rule[x].push_back(Rule(op, y, z));
      else rule[y].push_back(Rule(op, x, z));
   }

   bfs();

   return 0;
}