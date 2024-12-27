#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <string>
#include <sstream>

using namespace std;

bool canFormDesign(const string& design, const unordered_set<string>& towelPatterns) {
    int n = design.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;  // Base case: an empty design can always be formed

    // DP to check if the design can be formed
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && towelPatterns.count(design.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];  // Return if the entire design can be formed
}

int countPossibleDesigns(const vector<string>& towelPatterns, const vector<string>& designs) {
    unordered_set<string> towelPatternsSet(towelPatterns.begin(), towelPatterns.end());
    int count = 0;

    for (const string& design : designs) {
        if (canFormDesign(design, towelPatternsSet)) {
            count++;
        }
    }

    return count;
}

int main() {
    ifstream inputFile("input.txt");
    
    if (!inputFile.is_open()) {
        cerr << "Failed to open input file." << endl;
        return 1;
    }
    
    vector<string> towelPatterns;
    vector<string> designs;
    string line;
    
    // Reading towel patterns (first line)
    getline(inputFile, line);
    stringstream ss(line);
    string towelPattern;
    while (ss >> towelPattern) {
        towelPattern.pop_back();  // Remove the trailing comma
        towelPatterns.push_back(towelPattern);
    }
    
    // Skip the blank line
    getline(inputFile, line);
    
    // Reading designs (remaining lines)
    while (getline(inputFile, line)) {
        if (!line.empty()) {
            designs.push_back(line);
        }
    }
    
    inputFile.close();

    // Calculate and print the result
    int result = countPossibleDesigns(towelPatterns, designs);
    cout << result << endl;

    return 0;
}
