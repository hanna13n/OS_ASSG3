# CS3003D: Operating Systems

## Assignment – 3

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
