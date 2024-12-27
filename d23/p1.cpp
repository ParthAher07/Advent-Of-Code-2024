#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

// Function to find all triangles in the graph
vector<set<string>> findTriangles(const unordered_map<string, unordered_set<string>> &graph) {
    vector<set<string>> triangles;

    for (const auto &node1 : graph) {
        for (const auto &node2 : node1.second) {
            if (node1.first < node2) { // Ensure unique order
                for (const auto &node3 : graph.at(node2)) {
                    if (node3 > node1.first && graph.at(node1.first).count(node3)) {
                        // Found a triangle
                        triangles.push_back({node1.first, node2, node3});
                    }
                }
            }
        }
    }

    return triangles;
}

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    unordered_map<string, unordered_set<string>> graph;
    string line;

    // Read the input and build the graph
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string node1, node2;
        getline(ss, node1, '-');
        getline(ss, node2);

        graph[node1].insert(node2);
        graph[node2].insert(node1);
    }

    inputFile.close();

    // Find all triangles
    vector<set<string>> triangles = findTriangles(graph);

    // Count triangles containing at least one node starting with 't'
    int count = 0;
    for (const auto &triangle : triangles) {
        for (const auto &node : triangle) {
            if (node[0] == 't') {
                count++;
                break;
            }
        }
    }

    // Output the result
    cout << "Total triangles containing a node starting with 't': " << count/2 << endl;

    return 0;
}
