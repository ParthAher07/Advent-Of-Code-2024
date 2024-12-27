#include <bits/stdc++.h>

// Define constants
const unsigned int MODULO = 16777216;
const int NUM_CHANGES = 2000;
const int SEQUENCE_LENGTH = 4;

// Function to simulate secret number sequences and generate prices
std::vector<int> generate_prices(unsigned int initial_secret) {
    std::vector<int> prices;
    unsigned int secret_number = initial_secret;

    for (int i = 0; i <= NUM_CHANGES; ++i) {
        // Extract the price from the secret number
        prices.push_back(secret_number % 10);

        // Generate the next secret number
        unsigned int mix1 = (secret_number * 64) % MODULO;
        secret_number ^= mix1;
        secret_number %= MODULO;

        unsigned int mix2 = secret_number / 32;
        secret_number ^= mix2;
        secret_number %= MODULO;

        unsigned int mix3 = (secret_number * 2048) % MODULO;
        secret_number ^= mix3;
        secret_number %= MODULO;
    }

    return prices;
}

// Function to calculate changes from prices
std::vector<int> calculate_changes(const std::vector<int>& prices) {
    std::vector<int> changes;
    for (size_t i = 1; i < prices.size(); ++i) {
        changes.push_back(prices[i] - prices[i - 1]);
    }
    return changes;
}

int main() {
    // Read input from "input.txt"
    std::ifstream input_file("input.txt");
    if (!input_file) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return 1;
    }

    std::vector<unsigned int> initial_secrets;
    std::string line;
    while (std::getline(input_file, line)) {
        initial_secrets.push_back(std::stoul(line));
    }
    input_file.close();

    // Map to store sequence -> total bananas
    std::unordered_map<std::vector<int>, int, std::hash<std::string>> sequence_map;

    for (size_t buyer_index = 0; buyer_index < initial_secrets.size(); ++buyer_index) {
        std::vector<int> prices = generate_prices(initial_secrets[buyer_index]);
        std::vector<int> changes = calculate_changes(prices);

        for (size_t i = 0; i <= changes.size() - SEQUENCE_LENGTH; ++i) {
            std::vector<int> sequence(changes.begin() + i, changes.begin() + i + SEQUENCE_LENGTH);
            int price = prices[i + SEQUENCE_LENGTH];
            sequence_map[sequence] += price;
        }
    }

    // Find the sequence with the maximum total bananas
    int max_bananas = 0;
    std::vector<int> best_sequence;

    for (std::pair<const std::vector<int>, int> entry : sequence_map) {
        const std::vector<int>& sequence = entry.first;
        int total_bananas = entry.second;

        if (total_bananas > max_bananas) {
            max_bananas = total_bananas;
            best_sequence = sequence;
        }
    }

    // Output the result
    std::cout << "Max Bananas: " << max_bananas << std::endl;
    std::cout << "Best Sequence: ";
    for (size_t i = 0; i < best_sequence.size(); ++i) {
        std::cout << best_sequence[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
