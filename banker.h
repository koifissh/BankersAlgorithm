#include "library.h"
#include "process.h"

// Function prototype for menu function
void menu();

// Function prototype for calculate function
// This function calculates the safe sequence and updates the safeSequence vector
// processes: vector containing process information
// availableVector: vector containing available resources
// safeSequence: vector to store the safe sequence of processes
// needMatrix: vector containing the resource needs of each process
void calculate(vector<process>& processes, vector<int>& availableVector, vector<process>& safeSequence, vector<process>& needMatrix);

// Function prototype for processAsk function
// This function prompts the user to input resource allocation and maximum resource needs for each process
// processes: vector containing process information
// availableVector: vector containing available resources
// needMatrix: vector to store the resource needs of each process
void processAsk(vector<process>& processes, vector<int>& availableVector, vector<process>& needMatrix);
