#include <bits/stdc++.h>
using namespace std;

// Directions (East, South, West, North) and their corresponding moves
const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // East, South, West, North

// BFS to find the shortest path and identify the best path tiles
pair<int, set<pair<int, int>>> bfs_maze_with_paths(const vector<string>& maze, pair<int, int> start, pair<int, int> end) {
    int rows = maze.size();
    int cols = maze[0].size();

    // Distance map for BFS
    vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
    dist[start.first][start.second] = 0;

    // Queue for BFS
    queue<pair<int, int>> q;
    q.push(start);

    // Set to store all tiles that are part of the best paths
    set<pair<int, int>> best_path_tiles;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;

        // If we reach the end point, add it to best_path_tiles
        if (x == end.first && y == end.second) {
            best_path_tiles.insert({x, y});
        }

        // Explore neighbors
        for (int i = 0; i < 4; i++) {
            int dx = directions[i].first;
            int dy = directions[i].second;
            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && maze[nx][ny] != '#') {
                // If not visited or we found a shorter path to this tile
                if (dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                    best_path_tiles.insert({nx, ny});
                }
            }
        }
    }

    return make_pair(dist[end.first][end.second], best_path_tiles);
}

int main() {
    ifstream infile("input.txt");
    if (!infile) {
        cerr << "Error: Could not open input file!" << endl;
        return 1;
    }

    // Read the maze from the file
    vector<string> maze;
    string line;
    pair<int, int> start(-1, -1), end(-1, -1);

    int row = 0;
    while (getline(infile, line)) {
        maze.push_back(line);

        // Find start (S) and end (E)
        for (int col = 0; col < line.size(); ++col) {
            if (line[col] == 'S') {
                start = make_pair(row, col);
            }
            if (line[col] == 'E') {
                end = make_pair(row, col);
            }
        }
        ++row;
    }

    if (start == make_pair(-1, -1) || end == make_pair(-1, -1)) {
        cerr << "Error: Maze must contain both a start (S) and an end (E) point!" << endl;
        return 1;
    }

    // Compute the minimum score and best path tiles using BFS
    pair<int, set<pair<int, int>>> result = bfs_maze_with_paths(maze, start, end);
    int min_score = result.first;
    set<pair<int, int>> best_path_tiles = result.second;

    // Annotate the maze with the best paths
    for (set<pair<int, int>>::iterator it = best_path_tiles.begin(); it != best_path_tiles.end(); ++it) {
        int x = it->first;
        int y = it->second;
        if (maze[x][y] == '.') {
            maze[x][y] = 'O';  // Mark the tile as part of the best path
        }
    }

    // Output the annotated maze
    cout << "Annotated Maze:" << endl;
    for (int i = 0; i < maze.size(); ++i) {
        cout << maze[i] << endl;
    }

    // Output the result
    cout << "Number of tiles in best paths: " << best_path_tiles.size() << endl;

    return 0;
}
