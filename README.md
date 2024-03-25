
<p float="center">
    <p align="center"><img src="https://github.com/koifissh/BankersAlgorithm/assets/112574689/a4d73b5f-a7e8-49b2-9d3a-935eb4e3c398" width="350" />
      <p align="center"><img width="356" alt="Screenshot 2024-03-11 at 3 31 11 AM" src="https://github.com/koifissh/BankersAlgorithm/assets/112574689/1db6acc5-7181-4ef8-bbe9-211914cf8d26">
</p>

## Banker's Algorithm
Author: Daniel Huynh

## Statement
In this program, I have implemented a demonstration of Banker's algorithm using process data structures with resource allocation vectors within them. The program will generate a safe sequence for processes to execute. The program calculates the resource needs for each process through the allocation and max vectors which the user inputs into the program.

## Usage
To use this program, follow these steps:

1. Ensure that you have the necessary source and header files
2. The program will ask for the number of processes to demonstrate banker's algorithm with.
3. The user will be prompted to input the number of resources each process has
4. The program will prompt for the initial number of available resources at the time.
5. Next, the program will iterate through each process and ask for the allocation and max allocation of resources accordingly.
6. The program will output the allocation, max, and need matrix for all processes calculated from (max - allocation).
7. A safe sequence for execution will be generated based on banker's algorithm. If such sequence doesn't exist then the program will output an error.
   
<p align="center"><img width="250" alt="Screenshot 2024-03-11 at 3 23 11 AM" src="https://github.com/koifissh/BankersAlgorithm/assets/112574689/56d0467d-4463-4cbf-b0ea-3a59462cd856">

<p align="center"><img width="250" alt="Screenshot 2024-03-11 at 3 31 11 AM" src="https://github.com/koifissh/BankersAlgorithm/assets/112574689/1db6acc5-7181-4ef8-bbe9-211914cf8d26">
