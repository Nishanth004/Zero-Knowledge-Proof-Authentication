#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
#include <windows.h> // For Sleep()

using namespace std;

// Colors
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// ASCII Art
void displayHeader() {
    cout << MAGENTA << R"(
    __| |______________________________________________________________________________________________________________________________________________________________________| |__
    __   ______________________________________________________________________________________________________________________________________________________________________   __
      | |                                                                                                                                                                      | |  
      | |::::::::::::  .  ::::::::::.       :::.      ...    ::::::::::::::: ::   .: .,:::::::::.    :::.:::::::::::::::  .,-:::::   :::. :::::::::::::::    ...   :::.    :::.| |  
      | |'`````;;;;;; .;;,.`;;;```.;;;      ;;`;;     ;;     ;;;;;;;;;;;'''',;;   ;;,;;;;''''`;;;;,  `;;;;;;;;;;;'''';;;,;;;'````'   ;;`;;;;;;;;;;'''';;; .;;;;;;;.`;;;;,  `;;;| |  
      | |    .n[['[[[[[/'   `]]nnn]]'      ,[[ '[[,  [['     [[[     [[    ,[[[,,,[[[ [[cccc   [[[[[. '[[     [[     [[[[[[         ,[[ '[[,   [[     [[[,[[     \[[,[[[[[. '[[| |  
      | |  ,$$P" _$$$$,      $$$""        c$$$cc$$$c $$      $$$     $$    "$$$"""$$$ $$""""   $$$ "Y$c$$     $$     $$$$$$        c$$$cc$$$c  $$     $$$$$$,     $$$$$$ "Y$c$$| |  
      | |,888bo,_"888"88o,   888o          888   888,88    .d888     88,    888   "88o888oo,__ 888    Y88     88,    888`88bo,__,o, 888   888, 88,    888"888,_ _,88P888    Y88| |  
      | | `""*UMM MMM "MMP"  YMMMb         YMM   ""`  "YmmMMMM""     MMM    MMM    YMM""""YUMMMMMM     YM     MMM    MMM  "YUMMMMMP"YMM   ""`  MMM    MMM  "YMMMMMP" MMM     YM| |  
    __| |______________________________________________________________________________________________________________________________________________________________________| |__
    __   ______________________________________________________________________________________________________________________________________________________________________   __
      | |                                                                                                                                                                      | |  
    )" << RESET;
}

// System Info
void displaySystemInfo() {
    time_t now = time(0);
    char *dt = ctime(&now);
    cout << YELLOW << "Current Time: " << RESET << dt;
}

// Loading Animation
void loadingAnimation(const string &message) {
    cout << GREEN << message << RESET;
    for (int i = 0; i < 5; ++i) {
        cout << ".";
        cout.flush();
        Sleep(300); // 300ms
    }
    cout << endl;
}

// Progress Bar
void progressBar(const string &task) {
    cout << task << ": [";
    for (int i = 0; i <= 50; i++) {
        cout << "#";
        cout.flush();
        Sleep(50); // 50ms
    }
    cout << "] Done!" << endl;
}

// Logging System
void logMessage(const string &message) {
    ofstream logFile("project_log.txt", ios::app);
    logFile << message << endl;
    logFile.close();
    cout << YELLOW << "[LOG] " << RESET << message << endl;
}

// Function to execute Python scripts
void executePythonScript(const string &scriptName) {
    loadingAnimation("Running Python script");
    string command = "python " + scriptName; // Ensure Python is in PATH
    int result = system(command.c_str());
    if (result != 0) {
        cout << RED << "Failed to execute Python script: " << scriptName << RESET << endl;
    } else {
        logMessage("Successfully executed Python script: " + scriptName);
    }
}

// Function to execute C++ programs
void executeCppProgram(const string &programName) {
    loadingAnimation("Running C++ program");
    string command = programName; // Use "./" for Linux/Mac
    int result = system(command.c_str());
    if (result != 0) {
        cout << RED << "Failed to execute C++ program: " << programName << RESET << endl;
    } else {
        logMessage("Successfully executed C++ program: " + programName);
    }
}

// Easter Egg
void easterEgg() {
    cout << GREEN << R"(
         YOU FOUND AN EASTER EGG!
           ,     ,
          /(     )`
         (  \   /  )
         )   o o   (
        (    '='    )
         \         /
          \_______/
    )" << RESET << endl;
}

// Main Menu
int main() {
    displayHeader();
    displaySystemInfo();
    int choice;

    while (true) {
        cout << "\n" << CYAN << "Select a phase to execute:" << RESET << endl;
        cout << BOLD << GREEN
             << "1. Phase 1: Connection Check (Python)\n"
             << "2. Phase 2: Prime Number Generation (C++)\n"
             << "3. Phase 3: Registration (Python)\n"
             << "4. Phase 4: Compute y (C++)\n"
             << "5. Phase 5: Clear Memory (C++)\n"
             << "6. Phase 6: Check Connections (Python)\n"
             << "7. Phase 7: Server Send (C++)\n"
             << "8. Phase 8: Login (Python)\n"
             << "9. Phase 9: Client Receive (C++)\n"
             << "10. Phase 10: Compute r (C++)\n"
             << "11. Phase 11: Verification (C++)\n"
             << "12. EXIT\n"
             << RESET;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                executePythonScript("phase1.py");
                break;
            case 2:
                executeCppProgram("phase2");
                break;
            case 3:
                executePythonScript("phase3_registration.py");
                break;
            case 4:
                executeCppProgram("phase4");
                break;
            case 5:
                executeCppProgram("phase5");
                break;
            case 6:
                executePythonScript("phase6_connections.py");
                break;
            case 7:
                executeCppProgram("phase7");
                break;
            case 8:
                executePythonScript("phase8_login.py");
                break;
            case 9:
                executeCppProgram("phase9");
                break;
            case 10:
                executeCppProgram("phase10");
                break;
            case 11:
                executeCppProgram("phase11");
                break;
            case 12:
                logMessage("User exited the program.");
                cout << GREEN << "Goodbye!" << RESET << endl;
                return 0;
            case 42:  // Easter egg
                easterEgg();
                break;
            default:
                cout << RED << "Invalid choice. Please select a valid option." << RESET << endl;
        }
    }

    return 0;
}