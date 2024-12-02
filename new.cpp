#include <iostream>
#include <fstream>
#include <string>
#include <openssl/sha.h> // Requires OpenSSL for SHA-256

using namespace std;

// Function to hash the password
string hashPassword(const string &password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char *)password.c_str(), password.size(), hash);

    // Convert hash to hex string
    string hashedPassword;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        char buf[3];
        snprintf(buf, sizeof(buf), "%02x", hash[i]);
        hashedPassword += buf;
    }
    return hashedPassword;
}

int main() {
    // Read password from file
    ifstream passwordFile("password.txt");
    if (!passwordFile) {
        cerr << "Error: Password file not found.\n";
        return 1;
    }

    string password;
    getline(passwordFile, password);
    passwordFile.close();

    // Hash the password
    string hashedPassword = hashPassword(password);

    // Write the hashed password to a file
    ofstream outputFile("hashed_password.txt");
    if (!outputFile) {
        cerr << "Error: Unable to write hashed password to file.\n";
        return 1;
    }

    outputFile << hashedPassword;
    outputFile.close();

    return 0;
}
