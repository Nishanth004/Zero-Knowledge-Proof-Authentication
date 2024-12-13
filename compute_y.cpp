#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

// Function to perform modular exponentiation// Function to perform modular exponentiation
unsigned long long modularExponentiation(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    unsigned long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1; // Divide exp by 2
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    unsigned long long x, p, g;

    // Read x from hashed_password.txt
    ifstream xFile("hashed_password.txt");
    if (!xFile) {
        cerr << "Error: Unable to open hashed_password.txt.\n";
        return 1;
    }
    xFile >> x;
    xFile.close();

    // Read p from prime.txt
    ifstream pFile("prime.txt");
    if (!pFile) {
        cerr << "Error: Unable to open prime.txt.\n";
        return 1;
    }
    pFile >> p;
    pFile.close();

    // Read g from generator.txt
    ifstream gFile("generator.txt");
    if (!gFile) {
        cerr << "Error: Unable to open generator.txt.\n";
        return 1;
    }
    gFile >> g;
    gFile.close();

    // Compute y = g^x mod p
    unsigned long long y = modularExponentiation(g, x, p);

    // Output the result
    ofstream yFile("y.txt");
    if (!yFile) {
        cerr << "Error: Unable to write to y_value.txt.\n";
        return 1;
    }
    yFile << y;
    yFile.close();

    cout << "Computed y = g^x mod p. Result saved to y_value.txt\n";

    return 0;
}
