#include <iostream>
#include <fstream>
#include <string>
#include <cstdio> // For file deletion

void clearSensitiveFiles() {
    // List of sensitive files to be deleted
    const std::string sensitiveFiles[] = {"password.txt"};

    for (const auto &file : sensitiveFiles) {
        if (std::remove(file.c_str()) == 0) {
            std::cout << "Successfully deleted " << file << "\n";
        } else {
            std::cerr << "Failed to delete " << file << " or file does not exist.\n";
        }
    }
}

void retainValues() {
    // Retain g, y, and p by verifying they exist
    const std::string retainedFiles[] = {"generator.txt", "y.txt", "prime.txt"};

    for (const auto &file : retainedFiles) {
        std::ifstream inFile(file);
        if (inFile.good()) {
            std::cout << "Retained " << file << "\n";
        } else {
            std::cerr << "Error: " << file << " not found.\n";
        }
    }
}

int main() {
    std::cout << "Starting Phase 7: Clearing Sensitive Data...\n";

    // Step 1: Clear sensitive files
    clearSensitiveFiles();

    // Step 2: Retain g, y, and p
    retainValues();

    std::cout << "Phase 7 completed. Sensitive data cleared.\n";
    return 0;
}
