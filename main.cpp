#include <iostream>
#include <string>
#include <tuple>
#include <random>
#include <functional>
#include <limits>

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
unsigned long long simple_hash(const string &password, unsigned long long mod) {
    hash<string> hasher;
    return hasher(password) % mod;
}

bool is_prime(unsigned long long n) {
    if (n <= 1) return false;
    for (unsigned long long i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    unsigned long long p, g;
    string password, wrong_password;

    // Ensure p is a prime number and large enough
    do {
        cout << "Enter a prime number (p) greater than 1000: ";
        cin >> p;
    } while (!is_prime(p) || p <= 1000);

    // Ensure g is a valid generator (1 < g < p-1)
    do {
        cout << "Enter a generator (g) (1 < g < " << p-1 << "): ";
        cin >> g;
    } while (g <= 1 || g >= p-1);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter your password: ";
    getline(cin, password);

    // Step 1: Registration
    unsigned long long x = simple_hash(password, p - 1) + 1; // Ensure x is not 0

    // Peggy sends y = g^x mod p to Victor
    unsigned long long y = modular_pow(g, x, p);

    // Step 2: Authentication
    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<unsigned long long> dist(1, p - 2);

    cout << "Enter a wrong password for verification: ";
    getline(cin, wrong_password);
    unsigned long long wrong_x = simple_hash(wrong_password, p - 1) + 1; // Ensure wrong_x is not 0

    unsigned long long v = dist(gen);
    unsigned long long t = modular_pow(g, v, p);

    unsigned long long c = dist(gen);

    // Alice computes r = v - c * x, but uses the wrong x
    unsigned long long r = (v - c * wrong_x % (p - 1) + (p - 1)) % (p - 1);

    unsigned long long result = (modular_pow(g, r, p) * modular_pow(y, c, p)) % p;

    // Output the results
    cout << "\n====== Results ======\n";
    cout << "Correct Password:\t" << password << endl;
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