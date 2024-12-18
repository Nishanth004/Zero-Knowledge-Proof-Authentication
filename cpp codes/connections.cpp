

// #include <iostream>
// #include <fstream>
// #include <chrono>
// #include <string>

// using namespace std;

// // Simulate a delay with busy-waiting
// void simulateDelay(int milliseconds) {
//     auto start = chrono::steady_clock::now();
//     while (chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() < milliseconds) {
//         // Busy wait
//     }
// }

// // Function to display a dynamic progress indicator
// void showProgress(const string& message, int steps, int delayPerStep) {
//     cout << message << flush;
//     for (int i = 0; i < steps; ++i) {
//         simulateDelay(delayPerStep);  // Delay per step
//         cout << "." << flush;        // Append dots for progress
//     }
//     cout << endl;
// }

// void checkConnections() {
//     showProgress("Checking connections", 6, 400);  // Dynamic progress for 2.4 seconds

//     ifstream file("status.txt");
//     if (file.is_open()) {
//         string status;
//         getline(file, status);
//         file.close();
//         if (status == "yes") {
//             cout << "Connections are established." << endl;
//         } else {
//             cout << "Connections are NOT established." << endl;
//         }
//     } else {
//         cout << "Connections are NOT established." << endl;
//     }
// }

// void establishConnections() {
//     showProgress("Establishing connections", 6, 400);

//     ofstream file("status.txt");
//     file << "yes";
//     file.close();
//     cout << "Connections have been established." << endl;
// }

// void deEstablishConnections() {
//     showProgress("De-establishing connections", 6, 400);

//     ofstream file("status.txt");
//     file << "no";
//     file.close();
//     cout << "Connections have been de-established." << endl;
// }

// int main(int argc, char *argv[]) {
//     if (argc < 2) {
//         cerr << "Error: No operation specified." << endl;
//         return 1;
//     }

//     string operation = argv[1];

//     if (operation == "check") {
//         checkConnections();
//     } else if (operation == "establish") {
//         establishConnections();
//     } else if (operation == "de_establish") {
//         deEstablishConnections();
//     } else {
//         cerr << "Error: Unknown operation '" << operation << "'." << endl;
//         return 1;
//     }

//     return 0;
// }
#include <iostream>
#include <fstream>
#include <chrono>
#include <string>

using namespace std;

// Color codes for terminal output
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string RESET = "\033[0m";

// Simulate a delay with busy-waiting
void simulateDelay(int milliseconds) {
    auto start = chrono::steady_clock::now();
    while (chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() < milliseconds) {
        // Busy wait
    }
}

// Function to display a dynamic progress indicator
void showProgress(const string& message, int steps, int delayPerStep) {
    cout << BLUE << message << RESET << flush;
    for (int i = 0; i < steps; ++i) {
        simulateDelay(delayPerStep);  // Delay per step
        cout << "." << flush;        // Append dots for progress
    }
    cout << endl;
}

void checkConnections() {
    showProgress("Checking connections", 6, 400);  // Dynamic progress for 2.4 seconds

    ifstream file("status.txt");
    if (file.is_open()) {
        string status;
        getline(file, status);
        file.close();
        if (status == "yes") {
            cout << GREEN << "Connections are established." << RESET << endl;
        } else {
            cout << RED << "Connections are NOT established." << RESET << endl;
        }
    } else {
        cout << RED << "Connections are NOT established." << RESET << endl;
    }
}

void establishConnections() {
    showProgress("Establishing connections", 6, 400);

    ofstream file("status.txt");
    file << "yes";
    file.close();
    cout << GREEN << "Connections have been established." << RESET << endl;
}

void deEstablishConnections() {
    showProgress("De-establishing connections", 6, 400);

    ofstream file("status.txt");
    file << "no";
    file.close();
    cout << YELLOW << "Connections have been de-established." << RESET << endl;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << RED << "Error: No operation specified." << RESET << endl;
        return 1;
    }

    string operation = argv[1];

    if (operation == "check") {
        checkConnections();
    } else if (operation == "establish") {
        establishConnections();
    } else if (operation == "de_establish") {
        deEstablishConnections();
    } else {
        cerr << RED << "Error: Unknown operation '" << operation << "'." << RESET << endl;
        return 1;
    }

    return 0;
}
