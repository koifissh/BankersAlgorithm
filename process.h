#include "library.h"

struct process {
	int pid; // Process ID
	vector<int> allocation; // Vector to store resource allocation for the process

	// Max vector to store maximum resource needs of the process
	vector<int> max; 

	// Need vector to store the remaining resource needs of the process (Max - Allocation)
	vector<int> need; 

	// sequencePass indicates if the process has passed through the safe sequence
	bool sequencePass; 

	// finished indicates if the process has finished executing
	bool finished = false; // Initialized to false by default
};