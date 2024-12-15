#include <iostream>
#include <cstdlib>

using namespace std;

void executePythonScript(const string &scriptName) {
    string command = "python " + scriptName;
    int result = system(command.c_str());
    if (result != 0) {
        cout << "Failed to execute " << scriptName << endl;
    }
}

int main() {
    int choice;

    cout << "Select a Python script to execute:" << endl;
    cout << "1. Script 1 (e.g., save_password.py)" << endl;
    cout << "2. Script 2 (e.g., hash_password.py)" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    while(true) {
        switch (choice) {
            case 1:
                cout << "Running Script 1 (save_password.py)..." << endl;
                executePythonScript("phase1.py");
                break;

            case 2:
                cout << "Running Script 2 (hash_password.py)..." << endl;
                executePythonScript("hash_password.py");
                break;

            case 3:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}
