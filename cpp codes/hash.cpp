
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>

using namespace std;


unsigned long long simple_hash(const string &password, unsigned long long mod) {
    hash<string> hasher;
    return hasher(password) % mod;
}
int read_int_from_file(const string& filename) {
    ifstream file(filename);
    int value = 0;
    
    // Check if file exists and can be opened
    if (file.is_open()) {
        file >> value;
        file.close();
    } else {
        cerr << "Error: File not found or could not be opened: " << filename << endl;
        return -1;  // Return -1 to indicate an error
    }

    return value;
}

int main() {
    // Read the password from the file
    string password;
    ifstream passwordFile("password.txt");
    if (passwordFile.is_open()) {
        getline(passwordFile, password);
        passwordFile.close();
    } else {
        cerr << "Error: Unable to open password file.\n";
        return 1;
    }
    int p = read_int_from_file("prime.txt");

    // Generate a stronger hash
    unsigned long long hashed_password = simple_hash(password, p-1)+1;

    ofstream outputFile("hashed_password.txt");
    if (!outputFile) {
        cerr << "Error: Unable to write hashed password to file.\n";
        return 1;
    }

    outputFile << hashed_password;
    outputFile.close();

    return 0;
}


