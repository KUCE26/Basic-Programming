#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    int n, m;
    int grid[20][20];
    int dist[20][20];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            dist[i][j] = -1;
        }
    }
    queue<pair<int, int>> q;
    dist[0][0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = cur.first + dx[d];
            int ny = cur.second + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (grid[nx][ny] == 1 || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    cout << dist[n - 1][m - 1] << "\n";
    return 0;
}
