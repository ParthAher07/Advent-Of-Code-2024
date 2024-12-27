#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    vector<string> grid;
    string s;
    while (cin >> s) grid.push_back(s);

    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    long long totalPrice = 0;

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    auto isValid = [&](int x, int y, char plant) {
        return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == plant && !visited[x][y];
    };

    auto bfs = [&](int startX, int startY) {
        int area = 0;
        map<pair<int, int>, ll> corners;
        char plant = grid[startX][startY];
        queue<pair<int, int>> q;
        
        q.push({startX, startY});
        visited[startX][startY] = true;

        while (!q.empty()) {
            auto x = q.front().first;
            auto y = q.front().second;

            // Track corner points
            corners[{x,y}]++;
            corners[{x+1,y}]++;
            corners[{x,y+1}]++;
            corners[{x+1,y+1}]++;
            
            q.pop();
            area++;

            for (auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                if (isValid(nx, ny, plant)) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        auto edjecorner = [&](int x, int y) {
            return (x == 0 || y == 0 || x == rows || y == cols);
        };

        ll sides = 0;
        // Count sides based on corner point conditions
        for (auto& i : corners) {
            // Immediate corners (1 or 3 occurrences)
            if (i.second == 1 || i.second == 3) {
                sides++;
            }
            // Special case for points with 2 occurrences
            else if (i.second == 2) {

                int x = i.first.first;
                int y = i.first.second;
                if(edjecorner(x,y)) {
                    // cout<<"x: "<<x<<" y: "<<y<<endl;
                    // cout<<"outside\n";
                    continue;
                }

                // Check diagonal points
                if ((grid[x-1][y-1]==plant && grid[x][y]==plant) || 
                    (grid[x-1][y]==plant && grid[x][y-1]==plant)) {
                    sides += 2;
                    // cout<<"x: "<<x<<" y: "<<y<<" grid = "<<grid[x][y]<<endl;
                    // cout<<"D1 = "<<grid[x][y]<<" "<<grid[x+1][y+1]<<endl;
                    // cout<<"D2 = "<<grid[x][y+1]<<" "<<grid[x+1][y]<<endl;
                }
            }
        }

        // Debugging output
        cout << plant << " " << area << " " << sides << endl;

        return area * sides;
    };

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!visited[i][j]) {
                totalPrice += bfs(i, j);
            }
        }
    }

    cout << "Total Price: " << totalPrice << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}