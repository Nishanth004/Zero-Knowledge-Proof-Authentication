#include <iostream>
#include <cmath>
#include <random>
#include <fstream>
#include <unordered_set>

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

// Prime number generator tool
void primeNumberGenerator() {
    char choice;
    unsigned long long userNumber, suggestedPrime;
    unordered_set<unsigned long long> usedPrimes;

    while (true) {
        cout << "\n=== Phase 2: Prime Number Generation ===\n";
        cout << "Do you want to (e)nter your own number or (g)et a system-suggested prime? (e/g): ";
        cin >> choice;

        if (choice == 'e' || choice == 'E') {
            cout << "Enter your number: ";
            cin >> userNumber;

            if (isPrime(userNumber)) {
                cout << userNumber << " is a prime number.\n";
                break;  // Exit the loop after successful selection
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
            break;  // Exit the loop after successful selection
        } else {
            cout << "Invalid choice. Please select either 'e' or 'g'.\n";
        }
    }
    ofstream outputFile("prime.txt");
    if (!outputFile) {
        cerr << "Error: Unable to write prime to file.\n";
        return;
    }

    outputFile << suggestedPrime;
    outputFile.close();
}

int main() {
    primeNumberGenerator();
    return 0;
}
