#include <bits/stdc++.h>

using namespace std;

// Directions (East, South, West, North) and their corresponding moves
const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // East, South, West, North

int main() {
    ifstream infile("input.txt");
    
    // Read the maze from the file
    vector<string> maze;
    string line;
    pair<int, int> start, end;
    
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

    // Lambda function for BFS
    auto bfs_maze = [&] (const vector<string>& maze, pair<int, int> start, pair<int, int> end) -> int {
        int rows = maze.size();
        int cols = maze[0].size();
        
        // Priority queue for BFS with (score, x, y, direction)
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;
        pq.push(make_tuple(0, start.first, start.second, 0)); // Start with 0 score and direction East
        
        // Visited set to avoid revisiting same (x, y, direction)
        set<tuple<int, int, int>> visited;

        // Lambda to check if the state has been visited
        auto is_visited = [&visited](int x, int y, int dir) -> bool {
            return visited.find(make_tuple(x, y, dir)) != visited.end();
        };

        // Lambda to mark a state as visited
        auto mark_visited = [&visited](int x, int y, int dir) {
            visited.insert(make_tuple(x, y, dir));
        };

        mark_visited(start.first, start.second, 0);  // Mark the start as visited
        
        while (!pq.empty()) {
            tuple<int, int, int, int> current = pq.top();
            pq.pop();
            
            // Unpacking the tuple manually (no auto)
            int score = get<0>(current);
            int x = get<1>(current);
            int y = get<2>(current);
            int dir = get<3>(current);
            
            // If we've reached the end
            if (x == end.first && y == end.second) {
                return score;
            }
            
            // Move forward in the current direction
            int nx = x + directions[dir].first;
            int ny = y + directions[dir].second;
            
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && maze[nx][ny] != '#') {
                if (!is_visited(nx, ny, dir)) {
                    mark_visited(nx, ny, dir);
                    pq.push(make_tuple(score + 1, nx, ny, dir));
                }
            }
            
            // Rotate 90 degrees clockwise or counterclockwise
            for (int i : {-1, 1}) {
                int new_dir = (dir + i + 4) % 4;
                if (!is_visited(x, y, new_dir)) {
                    mark_visited(x, y, new_dir);
                    pq.push(make_tuple(score + 1000, x, y, new_dir));
                }
            }
        }
        
        return -1; // If no valid path found
    };

    // Compute the minimum score using the lambda function
    int score = bfs_maze(maze, start, end);
    
    // Output the result
    cout << "Minimum score: " << score << endl;
    
    return 0;
}
