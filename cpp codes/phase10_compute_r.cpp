// #include <iostream>
// #include <fstream>
// #include <string>
// #include <cstdlib>  // For rand() and srand()
// #include <ctime>    // For time() (used to seed the random number generator)

// // Function to read an integer value from a file
// int read_int_from_file(const std::string& filename) {
//     std::ifstream file(filename);
//     int value = 0;
    
//     // Check if file exists and can be opened
//     if (file.is_open()) {
//         file >> value;
//         file.close();
//     } else {
//         std::cerr << "Error: File not found or could not be opened: " << filename << std::endl;
//         return -1;  // Return -1 to indicate an error
//     }

//     return value;
// }

// // Function to write an integer value to a file
// void write_int_to_file(const std::string& filename, int value) {
//     std::ofstream file(filename);
    
//     if (file.is_open()) {
//         file << value << std::endl;  // Write the value followed by a newline
//         file.close();
//         std::cout << "Value " << value << " has been written to " << filename << std::endl;
//     } else {
//         std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
//     }
// }

// int main() {
//     // Read the necessary values from files
//     int x = read_int_from_file("hashed_password.txt");
//     int c = read_int_from_file("c.txt");  // Assuming the challenge value is stored in "challenge.txt"
//     int v = read_int_from_file("v.txt");  // Assuming the random value is stored in "random_value.txt"
//     int p = read_int_from_file("prime.txt");

//     // Check for errors in reading any of the values
//     if (x == -1 || c == -1 || v == -1 || p == -1) {
//         std::cerr << "Error: Failed to read one or more necessary values from files." << std::endl;
//         return 1;  // Exit the program if any value is missing
//     }

//     // Compute r using the formula r = (x + c * v) % (p - 1)
//     int r = (v - c * x % (p - 1) + (p - 1)) % (p - 1);

//     // Print the computed r
//     std::cout << "\nClient has computed r:" << std::endl;
//     std::cout << "r = " << r << std::endl;

//     // Write the value of r to r.txt
//     write_int_to_file("r.txt", r);

//     // Optionally, simulate sending r to the server
//     std::cout << "\nClient will send r to the server next." << std::endl;

//     return 0;
// }

#include <iostream>
#include <fstream>
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
int read_int_from_file(const std::string& filename) {
    std::ifstream file(filename);
    int value = 0;
    
    // Check if file exists and can be opened
    if (file.is_open()) {
        file >> value;
        if (!file.fail()) {
            file.close();
            return value;
        } else {
            cerr << RED << "Error: Failed to read integer from file: " << filename << RESET << endl;
            file.close();
            return -1;  // Return -1 to indicate an error
        }
    } else {
        cerr << RED << "Error: File not found or could not be opened: " << filename << RESET << endl;
        return -1;  // Return -1 to indicate an error
    }
}

// Function to write an integer value to a file
void write_int_to_file(const std::string& filename, int value) {
    std::ofstream file(filename);
    
    if (file.is_open()) {
        file << value << std::endl;  // Write the value followed by a newline
        file.close();
        cout << GREEN << "Value " << value << " has been written to " << filename << RESET << endl;
    } else {
        cerr << RED << "Error: Unable to open file " << filename << " for writing." << RESET << endl;
    }
}

int main() {
    // Read the necessary values from files
    int x = read_int_from_file("hashed_password.txt");
    int c = read_int_from_file("c.txt");  // Assuming the challenge value is stored in "c.txt"
    int v = read_int_from_file("v.txt");  // Assuming the random value is stored in "v.txt"
    int p = read_int_from_file("prime.txt");

    // Check for errors in reading any of the values
    if (x == -1 || c == -1 || v == -1 || p == -1) {
        cerr << RED << "Error: Failed to read one or more necessary values from files." << RESET << endl;
        return 1;  // Exit the program if any value is missing
    }

    // Compute r using the formula r = (x + c * v) % (p - 1)
    int r = (v - c * x % (p - 1) + (p - 1)) % (p - 1);

    // Print the computed r
    cout << BLUE << "\nClient has computed r:" << RESET << endl;
    cout << "r = " << r << endl;

    // Write the value of r to r.txt
    write_int_to_file("r.txt", r);

    // Optionally, simulate sending r to the server
    cout << BLUE << "\nClient will send r to the server next." << RESET << endl;

    return 0;
}
