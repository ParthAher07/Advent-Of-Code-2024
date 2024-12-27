#include <bits/stdc++.h>
using namespace std;

#define JAI_SHREE_RAM ios::sync_with_stdio(0); cin.tie(0);

typedef long long LL;
typedef pair<int, int> pii;

const int INF = INT_MAX;

void solve() {
    vector<string> grid;
    string s;
    while (getline(cin, s)) {
        if (s.empty()) break;
        grid.push_back(s);
    }

    int rows = grid.size(), cols = grid[0].size();
    pair<int, int> start, end;

    // Find start (S) and end (E) positions
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 'S') start = {i, j};
            if (grid[i][j] == 'E') end = {i, j};
        }
    }

    // BFS to find shortest path from start
    vector<vector<int>> dist(rows, vector<int>(cols, -1));
    queue<pii> q;
    dist[start.first][start.second] = 0;
    q.push(start);

    vector<int> dx = {-1, 1, 0, 0}; // Directions (up, down, left, right)
    vector<int> dy = {0, 0, -1, 1};

    while (!q.empty()) {
        auto x = q.front().first;
        auto y = q.front().second; q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] != '#' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    // If no path to the end exists
    if (dist[end.first][end.second] == INF) {
        cout << "No path exists.\n";
        return;
    }

    // Now calculate the best cheats
    int ans = 0;

    // Try every cell as a potential cheat start point
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '#' || dist[i][j] == INF) continue;

            for (int radius = 2; radius <= 20; radius++) {
                for (int nr = 0; nr <= radius; nr++) {
                    int ny = radius - nr;
                    set<pii> next = {{i + nr, j + ny}, {i + nr, j - ny}, {i - nr, j + ny}, {i - nr, j - ny}};
                    
                    for (auto p : next) {
                        int nx = p.first, ny = p.second;
                        if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && dist[nx][ny] != -1) {
                            if ((dist[i][j] - dist[nx][ny] )>= 100 + radius) {
                                ans++;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    JAI_SHREE_RAM;
    freopen("input.txt", "r", stdin);
    solve();
    return 0;
}
