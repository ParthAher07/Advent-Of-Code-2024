#include <bits/stdc++.h>
using namespace std;

int main() {
    cout<<"start\n";
    freopen("input.txt", "r", stdin);
    cout<<"open\n";
    vector<string> grid;
    string line;
    
    // Reading input grid
    while (cin >> line) {
        grid.push_back(line);
    }

    int n = grid.size();
    int m = grid[0].size();

    pair<int, int> guard_pos;
    
    // Find the starting position of the guard
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '^') {
                guard_pos = {i, j};
                break;
            }
        }
    }

    // Directions: up, right, down, left
    vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    set<pair<int, int>> possible_positions;

    // Function to simulate guard's movement with a given obstruction
    auto simulate = [&](int start_x, int start_y, int ob_x, int ob_y) {
        set<tuple<int, int, int>> visited; // To track visited states (x, y, direction)
        tuple<int, int, int> state = {start_x, start_y, 0}; // Initial state (x, y, direction)

        while (true) {
            int x = get<0>(state);
            int y = get<1>(state);
            int dir = get<2>(state);

            int next_x = x + directions[dir].first;
            int next_y = y + directions[dir].second;

            // Check for out of bounds
            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) {
                return false; // Out of bounds, no loop
            }

            // If we hit an obstruction or wall, change direction clockwise
            if ((next_x == ob_x && next_y == ob_y) || grid[next_x][next_y] == '#') {
                state = make_tuple(x, y, (dir + 1) % 4);
            } else {
                // Move to the next position
                state = make_tuple(next_x, next_y, dir);
            }

            // Check if we've seen this state before
            if (visited.count(state)) {
                return true; // Loop detected
            }
            visited.insert(state);
        }
    };

    // Try placing an obstruction at every empty spot and check if it causes a loop
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !(i == guard_pos.first && j == guard_pos.second)) {
                if (simulate(guard_pos.first, guard_pos.second, i, j)) {
                    possible_positions.insert({i, j});
                }
            }
        }
    }

    // Output the number of possible positions to place an obstruction
    cout << possible_positions.size() << endl;

    return 0;
}
