#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Function to check for the X-MAS pattern at a given position (x, y)
bool checkXMAS(const vector<string>& grid, int x, int y) {
    // Ensure we are within bounds of the grid
    if (x - 1 < 0 || x + 1 >= grid.size() || y - 1 < 0 || y + 1 >= grid[0].size()) {
        return false;
    }

    // Check both diagonals
    // Top-left to bottom-right diagonal
    char topLeft = grid[x - 1][y - 1];
    char bottomRight = grid[x + 1][y + 1];

    // Top-right to bottom-left diagonal
    char topRight = grid[x - 1][y + 1];
    char bottomLeft = grid[x + 1][y - 1];

    // We need exactly one 'M' and one 'S' on both diagonals
    bool validDiagonal1 = (topLeft == 'M' && bottomRight == 'S') || (topLeft == 'S' && bottomRight == 'M');
    bool validDiagonal2 = (topRight == 'M' && bottomLeft == 'S') || (topRight == 'S' && bottomLeft == 'M');

    return validDiagonal1 && validDiagonal2;
}

int countXMAS(const vector<string>& grid) {
    int count = 0;

    // Traverse each possible center of an X-MAS pattern (excluding the borders)
    for (int i = 1; i < grid.size() - 1; ++i) {
        for (int j = 1; j < grid[i].size() - 1; ++j) {
            if (checkXMAS(grid, i, j) && grid[i][j]=='A') {
                count++;
            }
        }
    }

    return count;
}

int main() {
    ifstream inputFile("input.txt");

    // Read input
    vector<string> grid;
    string line;
    while (getline(inputFile, line)) {
        grid.push_back(line);
    }

    // Count the number of X-MAS patterns
    int result = countXMAS(grid);
    cout << result << endl;

    return 0;
}
