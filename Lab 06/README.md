LAB TASK 💻: <br/>
<br/>    ▾ Write two C programs to compare the performance of buffered and unbuffered I/O operations by writing a string to a file 1 millions times. 

<br/>
<br/>    • Unbuffered I/O Program:

        • Use the 'open()' and 'write()' system calls for file operations.
        • This approach directly interacts with the system's I/O, causing the program to suspend with each write operation
<br/>
<br/>    • Buffered I/O Programs:

        • Use the 'fopen()' and 'fprintf()' functions from the C standard library for file operations.
        • Buffered I/O batches multiple outputs together, reducing the number of suspensions and potentially improving performances.
<br/>
<br/>    • Performance Measurement:

        • Incorporate the 'time()' function from '<time.h>' to measure the duration of the file writing operations.
        • Record the current time before starting and after completing the 1 million writes to calculate the elapsed time.
<br/>
<br/>    • Output Requirements:

        • Each program should output a message every time a write or print operation is performed.
        • At the end of execution, both progarms should display the total time elapsed during the 1 million writes to the terminal

