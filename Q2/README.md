# CS3003D: Operating Systems

## Assignment – 3

### 2. Course Instructor, TA and Students – Using Message Queue

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
