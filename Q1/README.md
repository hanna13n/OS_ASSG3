# CS3003D: Operating Systems

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
