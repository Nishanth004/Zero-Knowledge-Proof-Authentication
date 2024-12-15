#include <iostream>
#include <string>
#include <tuple>
#include <random>
#include <functional>
#include <limits>
#include <cmath>
#include <chrono>

using namespace std;

// Function for modular exponentiation: (base^exp) % mod
unsigned long long modular_pow(unsigned long long base, unsigned long long exp, unsigned long long mod) {
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

// Extended Euclidean Algorithm to find the modular inverse
tuple<long long, long long, long long> extended_euclidean_algorithm(long long a, long long b) {
    long long s = 0, old_s = 1;
    long long t = 1, old_t = 0;
    long long r = b, old_r = a;

    while (r != 0) {
        long long quotient = old_r / r;
        tie(old_r, r) = make_tuple(r, old_r - quotient * r);
        tie(old_s, s) = make_tuple(s, old_s - quotient * s);
        tie(old_t, t) = make_tuple(t, old_t - quotient * t);
    }
    return {old_r, old_s, old_t};
}

long long inverse_of(long long n, long long p) {
    long long gcd, x, y;
    tie(gcd, x, y) = extended_euclidean_algorithm(n, p);
    if (gcd != 1) {
        throw invalid_argument("No multiplicative inverse exists.");
    }
    return (x % p + p) % p;
}

// Simple hash function using std::hash
unsigned long long simple_hash(const string &input, unsigned long long mod) {
    hash<string> hasher;
    return hasher(input) % mod;
}

bool is_prime(unsigned long long n) {
    if (n <= 1) return false;
    for (unsigned long long i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Function to generate a random prime number greater than 1000
unsigned long long generate_random_prime() {
    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<unsigned long long> dist(1001, 100000);  // Limit the range of prime search

    unsigned long long p;
    int attempts = 0;
    do {
        p = dist(gen);
        attempts++;
        if (attempts % 100 == 0) {
            cout << "Attempting to find a prime... (Attempt " << attempts << ")\n";
        }
    } while (!is_prime(p));  // Generate until a prime is found
    return p;
}

// Function to generate a random generator `g` for the prime `p`
unsigned long long generate_random_generator(unsigned long long p) {
    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<unsigned long long> dist(2, p - 1);
    return dist(gen);
}

int main() {
    string username, password, wrong_password;

    // Step 1: Registration
    cout << "Enter your username: ";
    getline(cin, username);  // Take full input including spaces
    cout << "Enter your password: ";
    getline(cin, password);

    // Combine username and password to generate the secret x
    string combined = password; // Concatenate username and password
    unsigned long long x = simple_hash(combined, p-1
    ) + 1; // Ensure x is not 0

    // Debug: Print the computed x
    cout << "Computed x for correct password: " << x << endl;

    // Step 2: Authentication (Verification with random prime `p` and generator `g`)

    // Generate a random prime number p and generator g
    unsigned long long p = 4027;
    unsigned long long g = 3999;

    // Debug: Print p and g
    cout << "Generated prime p: " << p << endl;
    cout << "Generated generator g: " << g << endl;

    // Peggy sends y = g^x mod p to Victor
    unsigned long long y = modular_pow(g, x, p);

    // Step 3: User verification phase
    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<unsigned long long> dist(1, p - 2);

    // Debug: Ensure this output happens first before any other input
    cout << "\nEnter your username for verification: ";
    getline(cin, username); // Take full input
    cout << "Enter your password for verification: ";
    getline(cin, wrong_password); // Take full input

    // Combine the entered username and password for verification
    string wrong_combined =wrong_password; // Concatenate username and password
    unsigned long long wrong_x = simple_hash(wrong_combined, p-1) + 1; // Ensure wrong_x is not 0

    // Debug: Print x for the wrong password
    cout << "Computed x for wrong password: " << wrong_x << endl;

    unsigned long long v = dist(gen);
    unsigned long long t = modular_pow(g, v, p);

    unsigned long long c = dist(gen);

    // Alice computes r = v - c * x, but uses the wrong x
    unsigned long long r = (v - c * wrong_x % (p - 1) + (p - 1)) % (p - 1);

    unsigned long long result = (modular_pow(g, r, p) * modular_pow(y, c, p)) % p;

    // Output the results
    cout << "\n====== Results ======\n";
    cout << "Username:\t\t" << username << endl;
    cout << "Password:\t\t" << password << endl;
    cout << "Wrong Username:\t\t" << username << endl;
    cout << "Wrong Password:\t\t" << wrong_password << endl;
    cout << "Prime (p):\t\t" << p << endl;
    cout << "Generator (g):\t\t" << g << endl;
    cout << "x (hashed correct password):\t" << x << endl;
    cout << "x (hashed wrong password):\t" << wrong_x << endl;
    cout << "y = g^x mod p:\t\t" << y << endl;
    cout << "Random v:\t\t" << v << endl;
    cout << "Random challenge c:\t" << c << endl;
    cout << "r = (v - c * wrong_x) mod (p-1):\t" << r << endl;
    cout << "t = g^v mod p:\t\t" << t << endl;
    cout << "Verification result:\t" << result << endl;

    if (t == result) {
        cout << "Alice has proven she knows the password.\n";
    } else {
        cout << "Alice has NOT proven she knows the password.\n";
    }

    return 0;
}
