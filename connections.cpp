// // // #include <iostream>
// // // #include <fstream>

// // // class ConnectionManager {
// // // private:
// // //     bool connectionsInitialized;

// // // public:
// // //     ConnectionManager() : connectionsInitialized(false) {}

// // //     void initializeConnections() {
// // //         connectionsInitialized = true;
// // //         std::cout << "Connections have been successfully initialized.\n";

// // //         // Update status in a file to communicate with GUI
// // //         std::ofstream statusFile("status.txt");
// // //         statusFile << "Connections Initialized";
// // //         statusFile.close();
// // //     }
// // // };

// // // int main() {
// // //     ConnectionManager cm; 
// // //     cm.initializeConnections();
// // //     return 0;
// // // }

// // #include <iostream>
// // #include <chrono>
// // #include <thread> // Optional, only for time-related functions

// // using namespace std;

// // // Function to simulate checking connections
// // void checkConnections() {
// //     cout << "Checking connections..." << endl;

// //     // Simulate delay using a loop (not as efficient as threading, but works for this purpose)
// //     auto start = chrono::steady_clock::now();
// //     while (chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now() - start).count() < 2) {
// //         // Simulate delay by looping for 2 seconds
// //     }

// //     cout << "\nStatus: No ports or connections are currently established.\n";
// //     cout << "All connections are disabled.\n";

// //     // Indicate further actions
// //     cout << "\nNext Step: Prime number generation will be initiated in Phase 2.\n";
// // }

// // int main() {
// //     cout << "=== Phase 1: Connection Check ===\n";
// //     checkConnections();

// //     return 0;
// // }


// #include <iostream>
// #include <fstream>
// #include <string>

// using namespace std;

// int main() {
//     string status;
//     ifstream statusFile("status.txt");

//     if (!statusFile) {
//         // File doesn't exist, assume no connection
//         cout << "Status file not found. Assuming no connection.\n";
//         ofstream outFile("status.txt");
//         if (outFile) {
//             outFile << "no";
//         } else {
//             cerr << "Error: Unable to create status file.\n";
//             return 1;
//         }
//         status = "no";
//     } else {
//         getline(statusFile, status);
//         statusFile.close();
//     }

//     if (status == "yes") {
//         cout << "Connections are established.\n";
//     } else {
//         cout << "No ports or connections are established.\n";
//     }

//     return 0;
// }


// #include <iostream>
// #include <fstream>
// #include <chrono>

// using namespace std;

// // Function to simulate a delay (busy-wait loop)
// void simulateDelay(int milliseconds) {
//     auto start = chrono::steady_clock::now();
//     while (chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() < milliseconds) {
//         // Busy wait
//     }
// }

// // Function to simulate checking connections
// void checkConnections() {
//     cout << "Checking connections..." << flush;

//     // Simulate delay with a dynamic progress indicator
//     for (int i = 0; i < 6; ++i) {
//         simulateDelay(400); // Delay for 400ms
//         cout << "." << flush; // Append dots for progress visualization
//     }
//     cout << endl;

//     // Check the status file
//     ifstream statusFile("status.txt");
//     if (!statusFile) {
//         // If the file doesn't exist, assume no connection
//         cout << "\nStatus: No ports or connections are currently established.\n";
//         cout << "All connections are disabled.\n";

//         // Create the file and set default status to "no"
//         ofstream outFile("status.txt");
//         if (outFile) {
//             outFile << "no";
//         } else {
//             cerr << "Error: Unable to create status file.\n";
//             return;
//         }
//     } else {
//         // Read the status from the file
//         string status;
//         getline(statusFile, status);
//         statusFile.close();

//         if (status == "yes") {
//             cout << "\nStatus: Connections are established!\n";
//             cout << "You may proceed to the next phase.\n";
//         } else {
//             cout << "\nStatus: No ports or connections are currently established.\n";
//             cout << "All connections are disabled.\n";
//         }
//     }

//     // Indicate further actions
//     cout << "\nNext Step: Prime number generation will be initiated in Phase 2.\n";
// }

// int main() {
//     cout << "=== Phase 1: Connection Check ===\n";
//     checkConnections();

//     return 0;
// }

#include <iostream>
#include <fstream>
#include <chrono>
#include <string>

using namespace std;

// Simulate a delay with busy-waiting
void simulateDelay(int milliseconds) {
    auto start = chrono::steady_clock::now();
    while (chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() < milliseconds) {
        // Busy wait
    }
}

// Function to display a dynamic progress indicator
void showProgress(const string& message, int steps, int delayPerStep) {
    cout << message << flush;
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
            cout << "Connections are established." << endl;
        } else {
            cout << "Connections are NOT established." << endl;
        }
    } else {
        cout << "Connections are NOT established." << endl;
    }
}

void establishConnections() {
    showProgress("Establishing connections", 6, 400);

    ofstream file("status.txt");
    file << "yes";
    file.close();
    cout << "Connections have been established." << endl;
}

void deEstablishConnections() {
    showProgress("De-establishing connections", 6, 400);

    ofstream file("status.txt");
    file << "no";
    file.close();
    cout << "Connections have been de-established." << endl;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Error: No operation specified." << endl;
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
        cerr << "Error: Unknown operation '" << operation << "'." << endl;
        return 1;
    }

    return 0;
}
