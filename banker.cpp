#include "library.h"
#include "banker.h"



void processAsk(vector<process>& processes, vector<int>& availableVector, vector<process>& need) {
	int numProcesses;
	int numResources;
	//Ask for number of processes
	cout << "Enter the number of processes: ";
	cin >> numProcesses;
	//Ask for number of resources
	cout << "Enter the number of resources: ";
	cin >> numResources;

	cin.ignore(); // Ignore newline character after reading integer input
	
	//Loop to ask for process name and number of resources
	for (int i = 0; i < numProcesses; i++) {
		process newProcess;
		string lineInput;
		int numInput;
		
		//Name the process
		newProcess.pid = i;
		//Matrix inputs
		if (i == 0) {
			cout << "Enter the available vector: ";
			getline(cin, lineInput);
			istringstream iss(lineInput);
			while (iss >> numInput) {
				availableVector.push_back(numInput);
			}
		}

		cout << "Enter the allocation matrix for P" << i << ": ";
		getline(cin, lineInput);
		istringstream allocStream(lineInput);
		while (allocStream >> numInput) {
			newProcess.allocation.push_back(numInput);
		}

		cout << "Enter the max matrix for P" << i << ": ";
		getline(cin, lineInput);
		istringstream maxStream(lineInput);
		while (maxStream >> numInput) {
			newProcess.max.push_back(numInput);
		}
		
		// Need Matrix Calculation
		for (int j = 0; j < numResources; j++) {
			newProcess.need.push_back(newProcess.max[j] - newProcess.allocation[j]);
		}

		processes.push_back(newProcess);
	}

	//output allocation resource
	cout << "Allocation Matrix" << endl;
	for (int i = 0; i < numProcesses; i++) {
		cout << processes[i].pid << ": ";
		for (int j = 0; j < numResources; j++) {
			if (processes[i].allocation[j] < 0){
				//Output error if there is a negative number
				cout << "P" << i << " Error: Improper Allocation";
				exit(1);
			}
			cout << processes[i].allocation[j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	//Output the max resources required
	cout << "Max Matrix" << endl;
	for (int i = 0; i < numProcesses; i++) {
		cout << processes[i].pid << ": ";
		for (int j = 0; j < numResources; j++) {
			if (processes[i].max[j] < 0){
				//Output error if there is a negative number
				cout << "P" << i << " Error: Improper Allocation";
				exit(1);
			}
			cout << processes[i].max[j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	//Output the need matrix for the processes
	cout << "Need Matrix" << endl;
	for (int i = 0; i < numProcesses; i++) {
		cout << processes[i].pid << ": ";
		for (int j = 0; j < numResources; j++) {
			if (processes[i].need[j] < 0){
				//Output error if there is a negative number
				cout << "P" << i << " Error: Improper Allocation";
				exit(1);
			}
			cout << processes[i].need[j] << " ";
		}
		cout << endl;
	}
	
	//Output the available resources at the time
	cout << "Available Matrix" << endl;
	for (int i = 0; i < numResources; i++){
		cout << availableVector[i] << " ";
	}
	cout << endl;
}


//Function to navigate menu
void menu(){
	vector<process> processes;
	vector <int> availableVector;
	vector <process> needMatrix;
	vector <process> safeSequence;

	string userChoice = "Y";
	//Loop until the user quits
	while(userChoice == "Y"){
		processes.clear();
		availableVector.clear();
		needMatrix.clear();
		safeSequence.clear();
		//Ask for input
		processAsk(processes, availableVector, needMatrix);
		//Calculate Safe Sequence using banker's algoirthm
		calculate(processes, availableVector, safeSequence, needMatrix);
		cout << endl;
		cout << "Do you want to continue? (Y/N): ";
		cin >> userChoice;
	}
}

// Function to calculate safe sequence
void calculate(vector<process>& processes, vector<int>& availableVector, vector<process>& safeSequence, vector<process>& needMatrix) {
	
	int numProcesses = processes.size(); //set numProcess to process vector size for loop
	int numResources = availableVector.size(); //set numResources to vectorsize for loop
	
	int completionNum = 1;
	bool addedProcess;
	while(completionNum < numProcesses) {
		addedProcess = false; // Flag to track whether any process was added

		for(int i = 0; i < numProcesses; i++) {
			processes[i].sequencePass = true;

			// Check if the process is not finished
			if(processes[i].finished == false) {
				for(int j = 0; j < numResources; j++) {
					// If need is greater than available resources, set sequencePass flag to false and move to the next process to check
					if(processes[i].need[j] > availableVector[j]) {
						processes[i].sequencePass = false;
						break;
					}
				}

			// If sequencePass flag is true, add the process to the safe sequence	
			if(processes[i].sequencePass == true) {
				processes[i].finished = true; //Mark the indivdual process as added
				for(int k = 0; k < numResources; k++) {
					availableVector[k] += processes[i].allocation[k]; // Release allocated resources by adding them to the available vector
				}
				safeSequence.push_back(processes[i]);
				cout << "P" << i << " added to sequence" << endl;
				completionNum++; //Increment completion count
				addedProcess = true; // Set the flag to true indicating a process was added
				}
			}
		}//If procces was not added, then the system is in an unsafe state
		if(!addedProcess) {
			cout <<endl;
			cout << "Deadlock Detected" << endl;
			exit(0); // If no process is added, exit the loop
		}
		
	}
		// Output SAFE Sequence
		cout << endl;
		cout << "SAFE Sequence:";
		cout << endl;
		for(int i = 0; i < safeSequence.size(); i++){
			cout << "P"<< safeSequence[i].pid;
			if (i != safeSequence.size() - 1){
				cout << "->";
			}
		}
	
}