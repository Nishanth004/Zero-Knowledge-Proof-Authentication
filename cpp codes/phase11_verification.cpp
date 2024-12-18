// #include <iostream>
// #include <fstream>
// #include <cmath>
// #include <string>
// #include <cstdlib>  // For rand() and srand()
// #include <ctime>    // For time() (used to seed the random number generator)

// using namespace std;

// // Function to read an integer value from a file
// int read_int_from_file(const string& filename) {
//     ifstream file(filename);
//     int value = 0;
    
//     // Check if file exists and can be opened
//     if (file.is_open()) {
//         file >> value;
//         file.close();
//     } else {
//         cerr << "Error: File not found or could not be opened: " << filename << endl;
//         return -1;  // Return -1 to indicate an error
//     }

//     return value;
// }

// // Function to compute the modular exponentiation (base^exp % mod)
// int modular_pow(int base, int exp, int mod) {
//     int result = 1;
//     base = base % mod;  // In case base is larger than mod

//     while (exp > 0) {
//         if (exp % 2 == 1) {  // If exp is odd
//             result = (result * base) % mod;
//         }
//         exp = exp >> 1;  // exp = exp / 2
//         base = (base * base) % mod;  // base = base^2 % mod
//     }

//     return result;
// }

// int main() {
//     // Read the necessary values from files
//     int g = read_int_from_file("generator.txt");
//     int p = read_int_from_file("prime.txt");
//     int y = read_int_from_file("y.txt");
//     int c = read_int_from_file("c.txt");
//     int v = read_int_from_file("v.txt");
//     int r = read_int_from_file("r.txt");

//     // Check for errors in reading any of the values
//     if (g == -1 || p == -1 || y == -1 || c == -1 || v == -1 || r == -1) {
//         cerr << "Error: Failed to read one or more necessary values from files." << endl;
//         return 1;  // Exit the program if any value is missing
//     }

//     // Compute t = g^r % p
//     int t = modular_pow(g, v, p);

//     // Compute result = (y * v^c) % p
//     int v_c = modular_pow(v, c, p);  // Compute v^c % p
//     int result = (modular_pow(g, r, p) * modular_pow(y, c, p)) % p;

//     // Print the results
//     cout << "\nServer is verifying the response..." << endl;
//     cout << "Computed t =  " << t << endl;
//     cout << "Expected result =  " << result << endl;

//     // Verification step
//     if (t == result) {
//         cout << "\nVerification successful: Client's response is valid." << endl;
//     } else {
//         cout << "\nVerification failed: Client's response is invalid." << endl;
//     }

//     return 0;
// }
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time() (used to seed the random number generator)

using namespace std;

// Color codes for aesthetic output
const string RESET = "\033[0m";       // Reset color
const string GREEN = "\033[32m";      // Success messages
const string RED = "\033[31m";        // Error messages
const string BLUE = "\033[34m";       // Information messages

// Function to read an integer value from a file
int read_int_from_file(const string& filename) {
    ifstream file(filename);
    int value = 0;
    
    // Check if file exists and can be opened
    if (file.is_open()) {
        file >> value;
        if (!file.fail()) {
            file.close();
            return value;
        } else {
            cerr << RED << "Error: Invalid data in file: " << filename << RESET << endl;
            file.close();
            return -1;  // Return -1 to indicate an error
        }
    } else {
        cerr << RED << "Error: File not found or could not be opened: " << filename << RESET << endl;
        return -1;  // Return -1 to indicate an error
    }
}

// Function to compute the modular exponentiation (base^exp % mod)
int modular_pow(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;  // In case base is larger than mod

    while (exp > 0) {
        if (exp % 2 == 1) {  // If exp is odd
            result = (result * base) % mod;
        }
        exp = exp >> 1;  // exp = exp / 2
        base = (base * base) % mod;  // base = base^2 % mod
    }

    return result;
}

int main() {
    // Read the necessary values from files
    int g = read_int_from_file("generator.txt");
    int p = read_int_from_file("prime.txt");
    int y = read_int_from_file("y.txt");
    int c = read_int_from_file("c.txt");
    int v = read_int_from_file("v.txt");
    int r = read_int_from_file("r.txt");

    // Check for errors in reading any of the values
    if (g == -1 || p == -1 || y == -1 || c == -1 || v == -1 || r == -1) {
        cerr << RED << "Error: Failed to read one or more necessary values from files." << RESET << endl;
        return 1;  // Exit the program if any value is missing
    }

    // Compute t = g^r % p
    int t = modular_pow(g, r, p);

    // Compute result = (y * v^c) % p
    int v_c = modular_pow(v, c, p);  // Compute v^c % p
    int result = (modular_pow(g, r, p) * modular_pow(y, c, p)) % p;

    // Print the results
    cout << BLUE << "\nServer is verifying the response..." << RESET << endl;
    cout << "Computed t = " << t << endl;
    cout << "Expected result = " << result << endl;

    // Verification step
    if (t == result) {
        cout << GREEN << "\nVerification successful: Client's response is valid." << RESET << endl;
    } else {
        cout << RED << "\nVerification failed: Client's response is invalid." << RESET << endl;
    }

    return 0;
}
