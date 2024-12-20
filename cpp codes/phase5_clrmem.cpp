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
// #include <iostream>
// #include <fstream>
// #include <string>
// #include <cstdio> // For file deletion

// // Color codes for aesthetic output
// const std::string RESET = "\033[0m";       // Reset color
// const std::string GREEN = "\033[32m";      // Success messages
// const std::string RED = "\033[31m";        // Error messages
// const std::string YELLOW = "\033[33m";     // Warnings and information
// const std::string BLUE = "\033[34m";       // Info messages

// // Function to securely delete sensitive files
// void clearSensitiveFiles() {
//     // List of sensitive files to be deleted
//     const std::string sensitiveFiles[] = {"password.txt"};

//     for (const auto &file : sensitiveFiles) {
//         if (std::remove(file.c_str()) == 0) {
//             std::cout << GREEN << "Successfully deleted " << file << RESET << "\n";
//         } else {
//             std::cerr << RED << "Failed to delete " << file << " or file does not exist." << RESET << "\n";
//         }
//     }
// }

// // Function to retain files for generator, y, and prime
// void retainValues() {
//     // List of files to be retained
//     const std::string retainedFiles[] = {"generator.txt", "y.txt", "prime.txt"};

//     for (const auto &file : retainedFiles) {
//         std::ifstream inFile(file);
//         if (inFile.good()) {
//             std::cout << BLUE << "Retained " << file << RESET << "\n";
//         } else {
//             std::cerr << RED << "Error: " << file << " not found." << RESET << "\n";
//         }
//     }
// }

// int main() {
//     std::cout << YELLOW << "Starting Phase 7: Clearing Sensitive Data..." << RESET << "\n";

//     // Step 1: Clear sensitive files
//     clearSensitiveFiles();

//     // Step 2: Retain g, y, and p
//     retainValues();

//     std::cout << GREEN << "Phase 7 completed. Sensitive data cleared." << RESET << "\n";
//     return 0;
// }
