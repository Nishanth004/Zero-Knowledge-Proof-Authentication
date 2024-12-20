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
        cerr << "Error: Unable to write to y.txt.\n";
        return 1;
    }
    yFile << y;
    yFile.close();

    cout << "Computed y = g^x mod p. Result saved to y.txt\n";

    return 0;
}
// #include <iostream>
// #include <fstream>
// #include <string>
// #include <cmath>
// #include <chrono>

// using namespace std;

// // Color codes for aesthetic output
// const string RESET = "\033[0m";        // Reset color
// const string GREEN = "\033[32m";       // Success messages
// const string RED = "\033[31m";         // Error messages
// const string YELLOW = "\033[33m";      // Warnings and information
// const string BLUE = "\033[34m";        // Info messages

// // Function to perform modular exponentiation
// unsigned long long modularExponentiation(unsigned long long base, unsigned long long exp, unsigned long long mod) {
//     unsigned long long result = 1;
//     base = base % mod;
//     while (exp > 0) {
//         if (exp % 2 == 1) {
//             result = (result * base) % mod;
//         }
//         exp = exp >> 1;  // Divide exp by 2
//         base = (base * base) % mod;
//     }
//     return result;
// }

// // Secure file opening function
// bool openFile(ifstream &file, const string &filename) {
//     file.open(filename);
//     if (!file) {
//         cerr << RED << "Error: Unable to open " << filename << "." << RESET << endl;
//         return false;
//     }
//     return true;
// }

// // Secure file writing function
// bool openFile(ofstream &file, const string &filename) {
//     file.open(filename);
//     if (!file) {
//         cerr << RED << "Error: Unable to write to " << filename << "." << RESET << endl;
//         return false;
//     }
//     return true;
// }

// // Function to simulate a delay (busy-wait)
// void simulateDelay(int milliseconds) {
//     auto start = chrono::steady_clock::now();
//     while (chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() < milliseconds) {
//         // Busy-wait loop to simulate delay
//     }
// }

// // Function to display a progress bar with dots to simulate processing
// void showProgress(const string& message, int steps, int delayPerStep) {
//     cout << YELLOW << message << RESET << " [";
//     for (int i = 0; i < steps; ++i) {
//         cout << "." << flush;    // Display progress dots
//         simulateDelay(delayPerStep);  // Simulate delay with busy-wait
//     }
//     cout << "]" << RESET << endl;
// }

// int main() {
//     unsigned long long x, p, g;

//     ifstream xFile, pFile, gFile;

//     // Read x from hashed_password.txt
//     if (!openFile(xFile, "hashed_password.txt")) return 1;
//     xFile >> x;
//     xFile.close();

//     // Read p from prime.txt
//     if (!openFile(pFile, "prime.txt")) return 1;
//     pFile >> p;
//     pFile.close();

//     // Read g from generator.txt
//     if (!openFile(gFile, "generator.txt")) return 1;
//     gFile >> g;
//     gFile.close();

//     // Validate that the values are positive
//     if (x <= 0 || p <= 0 || g <= 0) {
//         cerr << RED << "Error: Invalid values in input files. All values must be positive." << RESET << endl;
//         return 1;
//     }

//     // Display a message indicating the start of the computation
//     cout << BLUE << "Starting the computation of y = g^x mod p..." << RESET << endl;

//     // Show progress bar
//     showProgress("Computing y = g^x mod p", 10, 200);  // Simulate progress with a 2-second progress bar

//     // Compute y = g^x mod p
//     unsigned long long y = modularExponentiation(g, x, p);

//     // Output the result to y.txt
//     ofstream yFile;
//     if (!openFile(yFile, "y.txt")) return 1;
//     yFile << y;
//     yFile.close();

//     // Display a success message
//     cout << GREEN << "Computation successful!" << RESET << endl;
//     cout << "The result y = g^x mod p is saved to y.txt: " << y << endl;

//     return 0;
// }
