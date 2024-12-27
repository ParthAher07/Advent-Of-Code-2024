#include <bits/stdc++.h>
using namespace std;

long long calculate_2000th_secret_number(unsigned int initial_secret) {
    const unsigned int MODULO = 16777216;

    unsigned int secret_number = initial_secret;
    for (int i = 0; i < 2000; ++i) {
   
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

    return secret_number;
}

int main() {
    
    ifstream input_file("input.txt");
    if (!input_file) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return 1;
    }

    vector<unsigned int> initial_secrets;
    string line;
    while (getline(input_file, line)) {
        initial_secrets.push_back(std::stoul(line));
    }
    input_file.close();

    long long result_sum = 0; 
    for (unsigned int secret : initial_secrets) {
        result_sum += calculate_2000th_secret_number(secret);
    }

    cout << result_sum << std::endl;

    return 0;
}
