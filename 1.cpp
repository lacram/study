#include <cstdio>
#include <queue>
#include <fstream>
using namespace std;
 
int n;
int arr[100][100], dist[100][100];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
 
void search()
{
    queue <pair<int, int>> q;
    q.push(make_pair(0, 0));
 
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (nx < n && ny < n && nx >= 0 && ny >= 0)
            {
                int ndist = arr[nx][ny] + dist[x][y];
                if (ndist < dist[nx][ny])
                {
                    q.push(make_pair(nx, ny));
                    dist[nx][ny] = ndist;
                }
            }
        }
    }
    return;
}
 
int main(){

  	ifstream cin;
	cin.open("input.txt");
 
    int t;
    scanf("%d", &t);
 
    for (int tc = 1; tc <= t; tc++)
    {
        scanf("%d", &n);
 
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                scanf("%1d", &arr[i][j]);
                dist[i][j] = 99999999;
            }
 
        dist[0][0] = 0;
        search();
 
        printf("#%d %d\n", tc, dist[n-1][n-1]);
    }
 
    return 0;
}