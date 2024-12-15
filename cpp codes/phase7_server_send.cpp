#include <iostream>
#include <fstream>
#include <string>

// Function to read values from a file
std::string read_from_file(const std::string& filename) {
    std::ifstream file(filename);
    std::string value;
    
    // Check if file exists and can be opened
    if (file.is_open()) {
        std::getline(file, value);  // Assuming one line per file
        file.close();
    } else {
        std::cerr << "Error: File not found or could not be opened: " << filename << std::endl;
        return "";  // Return an empty string to indicate failure
    }

    return value;
}

int main() {
    // Read values from the respective files
    std::string g = read_from_file("generator.txt");
    std::string y = read_from_file("y.txt");
    std::string p = read_from_file("prime.txt");

    // Check if any of the files failed to open
    if (g.empty() || y.empty() || p.empty()) {
        std::cerr << "Error: One or more required files are missing or could not be read." << std::endl;
        return 1;  // Exit the program with an error code
    }

    // Simulate sending values to the server by printing them
    std::cout << "Sending values to server:" << std::endl;
    std::cout << "g (generator): " << g << std::endl;
    std::cout << "y (computed value): " << y << std::endl;
    std::cout << "p (prime number): " << p << std::endl;

    // Optionally, simulate a "server response" by printing what the server might expect
    std::cout << "\nServer would now receive these values." << std::endl;

    return 0;
}
