#include <iostream>
#include <fstream>
#include <string>
#include <regex>

class Solution {
public:
    long PartOne(const std::string& input) {
        return Solve(input, std::regex(R"(mul\((\d{1,3}),(\d{1,3})\))"));
    }

    long PartTwo(const std::string& input) {
        return Solve(input, std::regex(R"(mul\((\d{1,3}),(\d{1,3})\)|don't\(\)|do\(\))"));
    }

private:
    long Solve(const std::string& input, const std::regex& rx) {
        auto matches_begin = std::sregex_iterator(input.begin(), input.end(), rx);
        auto matches_end = std::sregex_iterator();

        bool enabled = true;
        long result = 0;

        for (auto it = matches_begin; it != matches_end; ++it) {
            std::smatch match = *it;
            std::string match_str = match.str();

            if (match_str == "don't()") {
                enabled = false;
            } else if (match_str == "do()") {
                enabled = true;
            } else if (enabled && match.size() == 3) {
                int a = std::stoi(match[1].str());
                int b = std::stoi(match[2].str());
                result += a * b;
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    std::ifstream inputFile("input.txt");

    if (!inputFile) {
        std::cerr << "Error: Could not open input.txt" << std::endl;
        return 1;
    }

    std::string input((std::istreambuf_iterator<char>(inputFile)),
                      std::istreambuf_iterator<char>());

    inputFile.close();

    std::cout << "Part One: " << solution.PartOne(input) << std::endl;
    std::cout << "Part Two: " << solution.PartTwo(input) << std::endl;

    return 0;
}
