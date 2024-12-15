#include <iostream>
#include <cmath>
#include <random>
#include <fstream>
#include <unordered_set>
#include <limits>

using namespace std;

// Function to check if a number is prime
bool isPrime(unsigned long long n) {
    if (n <= 1) return false;
    if (n == 2) return true;  // 2 is prime
    if (n % 2 == 0) return false;  // No even number other than 2 is prime

    for (unsigned long long i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// Function to generate a random prime number
unsigned long long generateRandomPrime(unordered_set<unsigned long long>& usedPrimes) {
    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<unsigned long long> dist(1000, 10000);

    while (true) {
        unsigned long long candidate = dist(gen);
        if (isPrime(candidate) && usedPrimes.find(candidate) == usedPrimes.end()) {
            usedPrimes.insert(candidate);  // Mark this prime as used
            return candidate;
        }
    }
}

// Prime number generator tool - Console version
unsigned long long primeNumberGenerator() {
    char choice;
    unsigned long long userNumber, suggestedPrime;
    unordered_set<unsigned long long> usedPrimes;

    while (true) {
        cout << "\n=== Prime Number Generation ===\n";
        cout << "Do you want to (e)nter your own number or (g)et a system-suggested prime? (e/g): ";
        cin >> choice;

        if (choice == 'e' || choice == 'E') {
            cout << "Enter your number: ";
            cin >> userNumber;

            if (isPrime(userNumber)) {
                cout << userNumber << " is a prime number.\n";
                return userNumber;  // Return the prime number selected by the user
            } else {
                cout << userNumber << " is not a prime number.\n";
                cout << "Please try again.\n";
            }
        } else if (choice == 'g' || choice == 'G') {
            do {
                suggestedPrime = generateRandomPrime(usedPrimes);
                cout << "The system suggests the prime number: " << suggestedPrime << endl;
                cout << "Do you accept this prime number? (y/n): ";
                cin >> choice;
            } while (choice != 'y' && choice != 'Y');
            cout << "Prime number " << suggestedPrime << " has been selected.\n";
            return suggestedPrime;  // Return the system-generated prime number
        } else {
            cout << "Invalid choice. Please select either 'e' or 'g'.\n";
        }
    }
}

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

    ofstream outputFile("generator.txt");
    if (!outputFile) {
        cerr << "Error: Unable to write generator to file.\n";
        return;
    }

    outputFile << generator;
    outputFile.close();
}

int main() {
    // Prime number generation
    unsigned long long prime = primeNumberGenerator();

    // Save the selected prime number to a file
    ofstream primeFile("prime.txt");
    if (!primeFile) {
        cerr << "Error: Unable to write prime to file.\n";
        return 1;
    }

    primeFile << prime;
    primeFile.close();
    cout << "Prime number " << prime << " has been saved to prime.txt.\n";

    // Start Phase 3: Generator selection
    generatorSelection(prime);
    
    return 0;
}