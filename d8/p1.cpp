#include<bits/stdc++.h>
using namespace std;

// Function to check if a position is within the bounds of the map
bool isValid(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

// Function to calculate the number of unique antinode locations
int calculateAntinodes(const vector<string>& map) {
    int rows = map.size();
    int cols = map[0].size();

    unordered_set<string> antinodes; // Set to store unique antinode positions

    // Store positions of antennas by frequency
    unordered_map<char, vector<pair<int, int>>> antennas;
    
    // Scan the map and store antenna positions
    for (int x = 0; x < rows; ++x) {
        for (int y = 0; y < cols; ++y) {
            char c = map[x][y];
            if (c != '.') { // It's an antenna
                antennas[c].push_back({x, y});
            }
        }
    }

    // For each frequency, calculate the antinodes
    for (const auto& entry : antennas) {
        char frequency = entry.first;
        const auto& positions = entry.second;

        // Check every pair of antennas with the same frequency
        for (int i = 0; i < positions.size(); ++i) {
            for (int j = i + 1; j < positions.size(); ++j) {
                int x1 = positions[i].first, y1 = positions[i].second;
                int x2 = positions[j].first, y2 = positions[j].second;

                // Calculate the antinode positions
                
                int antinode1_x = x2 + (x2 - x1);
                int antinode1_y = y2 + (y2 - y1);
                int antinode2_x = x1 - (x2 - x1);
                int antinode2_y = y1 - (y2 - y1);

                // Add antinodes to the set if they're valid (within the map)
                if (isValid(antinode1_x, antinode1_y, rows, cols)) {
                    antinodes.insert(to_string(antinode1_x) + "," + to_string(antinode1_y));
                }
                if (isValid(antinode2_x, antinode2_y, rows, cols)) {
                    antinodes.insert(to_string(antinode2_x) + "," + to_string(antinode2_y));
                }
            }
        }
    }

    // Return the count of unique antinode positions
    return antinodes.size();
}

int main() {
    // Read the map from input.txt
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }

    vector<string> map;
    string line;
    while (getline(inputFile, line)) {
        map.push_back(line);
    }
    inputFile.close();

    int result = calculateAntinodes(map);

    cout << "Number of unique antinode locations: " << result << endl;

    return 0;
}
