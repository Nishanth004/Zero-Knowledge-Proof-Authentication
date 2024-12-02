#include <iostream>
#include <limits>
#include <fstream> 

using namespace std;

// Function to check if the generator is valid
bool isValidGenerator(unsigned long long g, unsigned long long p) {
    return g > 1 && g < p - 1;
}

// Generator selection tool
void generatorSelection(unsigned long long prime) {
    unsigned long long generator;

    cout << "\n=== Phase 3: Generator Selection ===\n";
    cout << "Explanation:\n";
    cout << "A generator (g) is a number such that all elements in the group (Z_p*) can be generated as powers of g modulo p.\n";
    cout << "It must satisfy: 1 < g < " << prime - 1 << "\n";

    while (true) {
        cout << "Enter a generator (g): ";
        cin >> generator;

        if (isValidGenerator(generator, prime)) {
            cout << "Generator " << generator << " has been selected.\n";
            break;  // Exit the loop after successful selection
        } else {
            cout << "Invalid generator. Please enter a value such that 1 < g < " << prime - 1 << ".\n";
        }
    }
    ofstream outputFile("generatorFile.txt");
    if (!outputFile) {
        cerr << "Error: Unable to write generator to file.\n";
        return;
    }

    outputFile << generator;
    outputFile.close();
}

int main() {
    // Simulate the prime number obtained from Phase 2
    unsigned long long prime = 2027;  // Replace this with the prime obtained from Phase 2

    // Start Phase 3
    generatorSelection(prime);

    return 0;
}
