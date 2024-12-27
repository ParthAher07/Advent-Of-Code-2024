#include <bits/stdc++.h>    

using namespace std;

// Directions for moving: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Function to check if a position is within bounds
bool isValid(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

// BFS function to explore the hiking trail from a trailhead
int bfs(const vector<vector<int>>& map, int startX, int startY) {
    int rows = map.size();
    int cols = map[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    int score = 0;

    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        // If we reach a height of 9, increase the score
        if (map[x][y] == 9) {
            score++;
        }

        // Explore the four possible directions
        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i], newY = y + dy[i];
            if (isValid(newX, newY, rows, cols) && map[newX][newY] == map[x][y] + 1) {
                visited[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }

    return score;
}

int main() {
    // Read the map from input
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
    int totalScore = 0;

    // Loop through the map to find all trailheads (positions with height 0)
    for (int x = 0; x < rows; ++x) {
        for (int y = 0; y < cols; ++y) {
            if (map[x][y] == 0) {
                // Calculate the score for this trailhead using BFS
                totalScore += bfs(map, x, y);
            }
        }
    }

    // Output the total score
    cout << "Total Score: " << totalScore << endl;

    return 0;
}
