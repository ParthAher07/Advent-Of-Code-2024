#include<bits/stdc++.h>
using namespace std;

// Directions for moving: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Function to check if a position is within bounds
bool isValid(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

// BFS function to explore the hiking trail from a trailhead
int bfs(const vector<vector<int>>& map, int startX, int startY, vector<vector<bool>>& visited, int& reachableNines) {
    int rows = map.size();
    int cols = map[0].size();
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        // Explore the four possible directions
        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i], newY = y + dy[i];
            if (isValid(newX, newY, rows, cols) && !visited[newX][newY] && map[newX][newY] == map[x][y] + 1) {
                visited[newX][newY] = true;
                q.push({newX, newY});
                
                // Check if we have reached a 9
                if (map[newX][newY] == 9) {
                    reachableNines++;
                }
            }
        }
    }

    return reachableNines;
}

int main() {
    freopen("input.txt", "r", stdin);
    vector<vector<int>> map;
    string line;
    while (getline(cin, line)) {
        vector<int> row;
        for (char c : line) {
            row.push_back(c - '0'); // Convert char to int
        }
        map.push_back(row);
    }

    int rows = map.size();
    int cols = map[0].size();
    int reachableNines = 0;

    // Loop through the map to find all trailheads (positions with height 0)
    for (int x = 0; x < rows; ++x) {
        for (int y = 0; y < cols; ++y) {
            if (map[x][y] == 0) {
                vector<vector<bool>> visited(rows, vector<bool>(cols, false));
                // Use BFS to explore and mark all reachable positions
                int t = 0;
                reachableNines+=bfs(map, x, y, visited, t);
            }
        }
    }

    // Output the total number of unique 9's reachable
    cout << "Total unique 9's reachable: " << reachableNines << endl;

    return 0;
}
