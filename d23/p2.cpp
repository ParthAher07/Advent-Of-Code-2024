#include <bits/stdc++.h>

using namespace std;

// Bron-Kerbosch algorithm to find the largest clique
void bronKerbosch(unordered_set<string> R, unordered_set<string> P, unordered_set<string> X,
                  const unordered_map<string, unordered_set<string>> &graph, unordered_set<string> &largestClique) {
    if (P.empty() && X.empty()) {
        if (R.size() > largestClique.size()) {
            largestClique = R;
        }
        return;
    }

    while (!P.empty()) {
        auto it = P.begin();
        string v = *it;
        P.erase(it);

        unordered_set<string> newR = R;
        newR.insert(v);

        unordered_set<string> newP;
        for (const string &neighbor : graph.at(v)) {
            if (P.count(neighbor)) {
                newP.insert(neighbor);
            }
        }

        unordered_set<string> newX;
        for (const string &neighbor : graph.at(v)) {
            if (X.count(neighbor)) {
                newX.insert(neighbor);
            }
        }

        bronKerbosch(newR, newP, newX, graph, largestClique);

        X.insert(v);
    }
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

    // Prepare for Bron-Kerbosch algorithm
    unordered_set<string> R, P, X;
    for (const auto &entry : graph) {
        P.insert(entry.first);
    }

    unordered_set<string> largestClique;
    bronKerbosch(R, P, X, graph, largestClique);

    // Sort the nodes in the largest clique alphabetically
    vector<string> sortedClique(largestClique.begin(), largestClique.end());
    sort(sortedClique.begin(), sortedClique.end());

    // Form the password
    string password = "";
    for (size_t i = 0; i < sortedClique.size(); ++i) {
        password += sortedClique[i];
        if (i < sortedClique.size() - 1) {
            password += ",";
        }
    }

    // Output the password
    cout << "Password to get into the LAN party: " << password << endl;

    return 0;
}
