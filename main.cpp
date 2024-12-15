#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// Function to execute Python scripts
void executePythonScript(const string &scriptName) {
    string command = "python " + scriptName; // Ensure Python is in PATH
    int result = system(command.c_str());
    if (result != 0) {
        cout << "Failed to execute Python script: " << scriptName << endl;
    }
}

// Function to execute C++ programs
void executeCppProgram(const string &programName) {
    string command = programName; // Directly execute without "./" for Windows
    int result = system(command.c_str());
    if (result != 0) {
        cout << "Failed to execute C++ program: " << programName << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\nSelect a phase to execute:" << endl;
        cout << "1. Phase 1: Connection Check (Python)" << endl;
        cout << "2. Phase 2: Prime Number Generation (C++)" << endl;
        cout << "3. Phase 3: Registration (Python)" << endl;
        cout << "4. Phase 4: Compute y (C++)" << endl;
        cout << "5. Phase 5: Clear Memory (C++)" << endl;
        cout << "6. Phase 6: Check Connections (Python)" << endl;
        cout << "7. Phase 7: Server Send (C++)" << endl;
        cout << "8. Phase 8: Login (Python)" << endl;
        cout << "9. Phase 9: Client Receive (C++)" << endl;
        cout << "10. Phase 10: Compute r (C++)" << endl;
        cout << "11. Phase 11: Verification (C++)" << endl;
        cout << "12. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Running Phase 1: Connection Check..." << endl;
                executePythonScript("phase1.py");
                break;

            case 2:
                cout << "Running Phase 2: Prime Number Generation..." << endl;
                executeCppProgram("phase2.exe");
                break;

            case 3:
                cout << "Running Phase 3: Registration..." << endl;
                executePythonScript("phase3_registration.py");
                break;

            case 4:
                cout << "Running Phase 4: Compute y..." << endl;
                executeCppProgram("phase4.exe");
                break;

            case 5:
                cout << "Running Phase 5: Clear Memory..." << endl;
                executeCppProgram("phase5.exe");
                break;

            case 6:
                cout << "Running Phase 6: Check Connections..." << endl;
                executePythonScript("phase6_connections.py");
                break;

            case 7:
                cout << "Running Phase 7: Server Send..." << endl;
                executeCppProgram("phase7.exe");
                break;

            case 8:
                cout << "Running Phase 8: Login..." << endl;
                executePythonScript("phase8_login.py");
                break;

            case 9:
                cout << "Running Phase 9: Client Receive..." << endl;
                executeCppProgram("phase9.exe");
                break;

            case 10:
                cout << "Running Phase 10: Compute r..." << endl;
                executeCppProgram("phase10.exe");
                break;

            case 11:
                cout << "Running Phase 11: Verification..." << endl;
                executeCppProgram("phase11.exe");
                break;

            case 12:
                cout << "Exiting the program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}
