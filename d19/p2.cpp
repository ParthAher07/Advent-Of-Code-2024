#include <bits/stdc++.h>

using namespace std;

long long canFormDesign(const string& design, const unordered_set<string>& towelPatterns) {
    long long n = design.size();
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;  // Base case: an empty design can always be formed

    // DP to check if the design can be formed
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j]>0 && towelPatterns.count(design.substr(j, i - j))) {
                //cout<<"i = "<<i<<" j = "<<j<<" dp[j] = "<<dp[j]<<endl;
                dp[i]+=dp[j];
                //cout<<"i = "<<i<<" j = "<<j<<" dp[i] = "<<dp[i]<<endl;
            }
        }
    }

    return dp[n];  // Return if the entire design can be formed
}

long long countPossibleDesigns(const vector<string>& towelPatterns, const vector<string>& designs) {
    unordered_set<string> towelPatternsSet(towelPatterns.begin(), towelPatterns.end());
    long long count = 0;

    for (const string& design : designs) {
        long long temp = canFormDesign(design, towelPatternsSet);
        cout<<temp<<endl;
        count+=temp;
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
        if(towelPattern.back() == ',' ) towelPattern.pop_back();  // Remove the trailing comma
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
    long long result = countPossibleDesigns(towelPatterns, designs);
    cout << result << endl;

    return 0;
}
