# OCS3003D: Operating Systems

## Assignment – 3

### 1. Password Strength Calculator – Using Shared memory

- **Procedure**  
  Compile and Run the file Q1.c and enter the input.
- **Filenames**  
  Q1.c
- **Processes**  
  P1, P2, P3
- **Input**  
  Character array (password) of length 10
- **Output**  
  Strength of the input password ( Strong / Weak )
- **Explanation**  
  P1 creates shared memory for the password. Reads the input into the shared memory and forks. P2 is created upon forking. P1 then waits for the child P2.  
  P2 calculates the number of alphanumeric characters and special characters in the password and saves it in the shared memory. P2 forks and P3 is created. P2 waits for its child P3.  
  P3 writes the strength of the password based on calculations of P2 into the shared memory and exits. Then P2 exits upon the exit of P3 and then P1 wakes up and prints the strength of the password from the shared memory into terminal.

- **Screenshots**  
  &nbsp;  
  ![Q1](/Q1/Q1.jpeg)

### 2. Using Message Queue

- **Procedure**  
  Compile and Run the files CI.c, TA.c and students.c concurrently and enter the marks of each student as input to CI.c
- **Filenames**  
  CI.c, TA.c, students.c
- **Processes**  
  CI, TA, S1, S2, S3, S4, S5
- **Input**  
  Marks (out of 50) of 5 students
- **Output**  
  The class average marks and the grades and marks of each student
- **Explanation**  
  Process CI creates a message queue and reads the marks of each student as input and sends all the marks to the message queue twice. The TA process recieves the marks of all students and calculates average and grades of each student and sends it to the message queue. The students.c program forks four times so that each student has a process. Each student process( S1,...,S5 ) recieves the respective message containg the mark of that respective student and prints it to the terminal. The CI.c program recieves the message with grades of each student and the average mark sent by TA.c and prints them on the terminal.

- **Screenshots**  
  &nbsp;  
  ![Q2](/Q2/Q2.jpeg)

### 3. Bankers Algorithm

- **Procedure**  
  Compile and Run the file Q3.c
- **Filenames**  
  Q3.c
- **Processes**  
  P1
- **Input**  
  No. of Processes, No. of Resources, Allocation Table, Max Table, Total Available Instances per Resource, Appropriate Choice from the menu and respective inputs.
- **Output**  
  Appropriate output respective to the input choice.
- **Explanation**  
  The program has 3 functions.

  - **safe_state_seq()**
    - **Arguments** : no. of processes, no. of resources, Available matrix, Need matrix, Allocation table, sequence array
    - **Return Value** : 0 or 1 (int)
    - Returns 1 and stores the safe state sequence in the seq array passed as argument, if a safe state is possible for the given system of processes.
    - Returns 0 if no safe state is possible.
  - **is_safe()**
    - **Arguments** : no. of processes, no. of resources, Available matrix, Need matrix, Allocation table, sequence array
    - **Return Value** : 0 or 1 (int)
    - Returns 1 if the given sequence of processes is a safe state, else returns 0.
  - **can_grant()**
    - **Arguments** : no. of processes, no. of resources, Available matrix, Need matrix, Allocation table, process of request, resource request array
    - **Return Value** : 0 or 1 (int)
    - Returns 1 if the given resource request of a process can be granted, else returns 0.
  - **main()**
    - **Arguments** : None
    - **Return Value** : 0 (int)
    - Reads the Allocation Table, Max Table and Total Available Instances per Resource as inputs and computes the Available matrix and Need matrix. Presents the menu with the respective choices and calls the respective function according to the input choice.  
      **The Input Choices are a, b, c or d**  
       a. Print the SAFE STATE Sequence  
       b. Check if the sequence is in SAFE STATE  
       c. Check if request can be granted  
       d. Exit

- **Screenshots**  
  &nbsp;  
  ![Q3_a](/Q3/Q3_a.jpeg)  
  ![Q3_b](/Q3/Q3_b.jpeg)
