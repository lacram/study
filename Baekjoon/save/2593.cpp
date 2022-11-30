#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
typedef pair<int, int> p;
 
int n, m, dep, des;
//시작층, 간격
p els[101];
//이전에 탄 엘리베이터와 갈아탄 횟수를 기록
int visit[101], dist[101];
bool possible[101];
vector<int> finishes;
vector<int> path;
 
bool iscon(p a, p b) {
    //엘리베이터 a와 b가 연결되어 있는지 확인
    int item = b.first;
    if (a.first == b.first) return true;
    while (item <= n) {
        if (item >= a.first && (item - a.first) % a.second == 0) return true;
        item += b.second;
    }
    return false;
}
 
void bfs(int num) {
    //num번째 엘리베이터에서 출발해 옮겨탈 수 있는 모든 엘리베이터를 탐색
    //큐 : 엘리베이터를 탄 횟수, 엘리베이터 번호
    queue<p> que;
    que.push({ 1, num });
    visit[num] = num;
    dist[num] = 1;
 
    while (!que.empty()) {
        p cur = que.front();
        que.pop();
 
        int distval = cur.first;
        int elnum = cur.second;
 
        //목표층에 도달할 수 있다면  종료
        //이 때 elnum은 num에서 목표 층에 도달하는 
        //가장 빠른 경로의 마지막 직전 엘리베이터이다
        if (possible[elnum]) continue;
 
        //다른 모든 엘리베이터에 대해
        for (int i = 1; i <= m; i++) {
            if (i == elnum) continue;
            //현재 엘리베이터에서 옮겨탈 수 있는 엘리베이터인가?
            if (iscon(els[elnum], els[i])) {
                //이미 방문한 엘리베이터라도 더 빨리 도착할 수 있다면 갱신함
                if (dist[i] > distval + 1) {
                    dist[i] = distval + 1;
                    visit[i] = elnum;
                    que.push({ distval + 1, i });
                }
            }
        }
    }
}
 
void init() {
    int d, interv;
    fill(visit, visit + 101, -1);
    fill(dist, dist + 101, 999);
    cin >> n >> m;
 
    for (int i = 1; i <= m; i++) {
        cin >> d >> interv;
        els[i] = { d, interv };
    }
 
    cin >> dep >> des;
 
    for (int i = 1; i <= m; i++) {
        if (els[i].first <= des && (des - els[i].first) % els[i].second == 0) {
            //목표층에 도달가능한지 기록. 즉, finish인지 기록
            possible[i] = true;
            finishes.push_back(i);
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);
 
    init();
 
    int answer = 999;
    int finish = -1;
    for (int i = 1; i <= m; i++) {
        //출발 층에 도달 가능한 엘리베이터에 대해서만
        if (dep < els[i].first ||(dep - els[i].first) % els[i].second != 0) continue;
        if (possible[i]) {
            printf("1\n%d\n", i);
            return 0;
        }
        bfs(i);
    }
 
    for (int i = 0; i < finishes.size(); i++) {
        //최소거리로 목표층에 도착했을 때의 마지막 엘리베이터 찾기
        if (answer > dist[finishes[i]]) {
            answer = dist[finishes[i]];
            finish = finishes[i];
        }
    }
 
    if (answer >= 999 || finish == -1) {
        //도달 불가
        printf("-1\n");
        return 0;
    }
 
    printf("%d\n", answer);
    while (1) {
        //경로 찾기
        path.push_back(finish);
        if (finish == visit[finish]) break;
        finish = visit[finish];
    }
 
    for (int i = path.size() - 1; i >= 0; i--) printf("%d\n", path[i]);
 
    return 0;
}
