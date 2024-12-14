#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time() (used to seed the random number generator)
#include <chrono>   // For high resolution time measurement
#include <random>   // For random number generation
#include <fstream> 
#include <string>
#include <cmath>

using namespace std;

// Function to simulate random packet loss (returning false to simulate packet loss)
bool simulate_packet_loss(double loss_probability = 0.1) {
    // Generate a random number between 0 and 1 and compare it with the loss probability
    return (static_cast<double>(rand()) / RAND_MAX) > loss_probability;
}

// Function to simulate delay (in milliseconds)
void simulate_delay(int max_delay_ms = 2000) {
    // Generate a random delay time
    int delay = rand() % max_delay_ms;
    
    // Use a simple loop to simulate delay
    clock_t start_time = clock();
    while (clock() < start_time + delay * (CLOCKS_PER_SEC / 1000));  // Simulating delay in ms
}

int main() {
    // Seed the random number generator to get different random values each time
    srand(time(nullptr));

    // Simulate delay before receiving the challenge
    cout << "Waiting for server response..." << endl;
    simulate_delay();  // Introduce a random delay before receiving the challenge

    // Simulate packet loss (10% chance of packet loss)
    if (!simulate_packet_loss(0.1)) {
        cerr << "Error: Packet loss occurred. Challenge not received." << endl;
        return 1;  // Exit the program on packet loss
    }

    // Generate random values for c (challenge) and v (random value)
    int c = rand() % 1000;  // Random challenge value (e.g., between 0 and 999)
    int v = rand() % 1000;  // Random value related to the challenge

    // Simulate a timeout scenario (e.g., if challenge isn't received within a reasonable time)
    int timeout_threshold = 5000;  // 5 seconds timeout for example
    clock_t start_time = clock();
    int elapsed_time = 0;

    while (elapsed_time < timeout_threshold) {
        // Check if enough time has passed
        elapsed_time = (clock() - start_time) * 1000 / CLOCKS_PER_SEC;  // Time in milliseconds

        // Simulate packet loss again (10% chance of packet loss)
        if (simulate_packet_loss(0.1)) {
            break;  // Assume challenge received successfully if no packet loss
        }
    }

    if (elapsed_time >= timeout_threshold) {
        cerr << "Error: Timeout occurred while waiting for challenge from server." << endl;
        return 1;
    }

    // If no timeout and no packet loss, simulate successful reception of challenge
    cout << "\nChallenge successfully received from server:" << endl;
    cout << "c (challenge): " << c << endl;
    cout << "v (random value): " << v << endl;

    // Save the challenge to "c.txt"
    ofstream cFile("c.txt");
    if (!cFile) {
        cout << "Error: Unable to write to c.txt.\n";
        return 1;
    }
    cFile << c;
    cFile.close();
    cout << "Received random challenge has been saved to c.txt\n";

    // Save the random value to "v.txt"
    ofstream vFile("v.txt");
    if (!vFile) {
        cout << "Error: Unable to write to v.txt.\n";
        return 1;
    }
    vFile << v;
    vFile.close();
    cout << "Received random value has been saved to v.txt\n";

    cout << "\nServer has sent these values for the client to use." << endl;

    return 0;
}
